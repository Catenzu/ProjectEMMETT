/*
 * Emmett
 */

#include "../include/emmett.h"

MOS6502::MOS6502()
{
    a.set(0);
    x.set(0);
    y.set(0);
    sp.set(0);
    sr.set(0);
    pc = 0;
};

void MOS6502::clear()
{
    a.set(0);
    x.set(0);
    y.set(0);
    sp.set(0);
    sr.set(0);
    pc = 0;

    for (auto & i : memory)
        i.set(0);
};

void MOS6502::reset()
{
    int pc1 = memory[0xFFFC]._value;
    int pc2 = memory[0xFFFD]._value;

    pc = (pc2 << 8) | pc1;
    sp.set(0x00);
    sr.set(0x00);
    x.set(0x00);
    y.set(0x00);
    a.set(0x00);
};

unsigned char MOS6502::fetch(int &cycles) //take one cycle
{
    uint16_t address = pc;
    pc++;
    cycles--;
    return memory[address]._value;
};

unsigned char MOS6502::fetchX(int &cycles) //take one cycle
{;
    cycles--;
    return x._value;
};

unsigned char MOS6502::fetchY(int &cycles) //take one cycle
{
    cycles--;
    return y._value;
};

int MOS6502::execute(int cycles)
{
    while (cycles > 0) {
        unsigned char opcode = fetch(cycles);

     for (auto &operation : operations)
            if (operation.opcode == opcode) {
                (this->*operation.operate)(cycles);
                break;
            }
    }
    return cycles;
}

void MOS6502::setZeroFlag(unsigned char value)
{
    if (value == 0)
        sr._value = sr._value | 0b00000010; //set the 7th bit to 1
}

void MOS6502::setNegativeFlag(unsigned char value)
{
    if (value & 0b10000000) //if the 7th bit is 1
        sr._value = sr._value | 0b10000000; //set the 0th bit to 1
}

void MOS6502::setMemory(uint16_t address, unsigned char value)
{
    if (address > 0xFFFF || address < 0xFFFF) {
        std::cerr << "SetMemory: Invalid address at " << address << std::endl;
        return;
    }
    if (value > 0xFF || value < 0x00) {
        std::cerr << "SetMemory: Invalid value: " << value << std::endl;
        return;
    }
    memory[address].set(value);
}

unsigned char MOS6502::getMemory(uint16_t address, int &cycles)
{
    if (address > 0xFFFF || address < 0x0000) {
        std::cerr << "GetMemory: Invalid address at " << address << std::endl;
        return 0;
    }
    cycles--;
    return memory[address]._value;
}
