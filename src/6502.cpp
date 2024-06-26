/*
 * Emmett
 */

#include "../include/emmett.h"

MOS6502::MOS6502()
{
    _a.set(0);
    _x.set(0);
    _y.set(0);
    _sp.set(0xFF);
    _sr.set(0);
    _pc = 0;
    _isInDebugMode = false;
    _debugPrint = false;
    _aluAdditionCarry = false;

    _return = false;
};

void MOS6502::clear()
{
    _a.set(0);
    _x.set(0);
    _y.set(0);
    _sp.set(0xFF);
    _sr.set(0);
    _pc = 0;
    _aluAdditionCarry = false;

    for (auto & i : _memory)
        i.set(0);
};

void MOS6502::reset()
{
    int pc1 = _memory[0xFFFC]._value;
    int pc2 = _memory[0xFFFD]._value;

    _pc = (pc2 << 8) | pc1;
    _sp.set(0xFF);
    _sr.set(0x00);
    _x.set(0x00);
    _y.set(0x00);
    _a.set(0x00);
};

unsigned char MOS6502::fetch(int &cycles) //take one cycle
{
    uint16_t address = _pc;
    _pc++;
    cycles--;
    return _memory[address]._value;
};

int MOS6502::execute(int cycles)
{
    bool infiniteLoop = false;

    if (cycles == -1)
        infiniteLoop = true;

    while (cycles > 0 || infiniteLoop) {
        unsigned char opcode = fetch(cycles);

        for (auto &operation : operations)
            if (operation.opcode == opcode) {
                (this->*operation.operate)(cycles);
                break;
            }
        if (_isInDebugMode) //debug mode, to see if it's the exact number of cycles
            break;
        if (_return) {
            _return = false;
            std::cout << "Return " << (int)_a._value << std::endl;
            return cycles;
        }
    }
    return cycles;
}

unsigned char MOS6502::aluAddition(unsigned char componentA, unsigned char componentB, int &cycles)
{
    uint16_t result = componentA + componentB;
    unsigned char result8 = result & 0xFF;
    if (result > 0xFF) //if the result is bigger than 255
        _aluAdditionCarry = true;
    else
        _aluAdditionCarry = false;
    cycles--;
    return result8;
}

void MOS6502::setZeroFlagFromByte(unsigned char value)
{
    if (value == 0)
        _sr._value = _sr._value | 0b00000010; //set the 1th bit to 1
    else
        _sr._value = _sr._value & 0b11111101; //set the 1th bit to 0
}

void MOS6502::setNegativeFlagFromByte(unsigned char value)
{
    if (value & 0b10000000) //if the 7th bit is 1
        _sr._value = _sr._value | 0b10000000; //set the 7th bit to 1
    else
        _sr._value = _sr._value & 0b01111111; //set the 7th bit to 0
}

void MOS6502::setZeroFlag(bool value)
{
    if (value)
        _sr._value = _sr._value | 0b00000010; //set the 0th bit to 1
    else
        _sr._value = _sr._value & 0b11111101; //set the 0th bit to 0
}

void MOS6502::setNegativeFlag(bool value)
{
    if (value)
        _sr._value = _sr._value | 0b10000000; //set the 6th bit to 1
    else
        _sr._value = _sr._value & 0b01111111; //set the 6th bit to 0
}

void MOS6502::setCarryFlag(bool value)
{
    if (value)
        _sr._value = _sr._value | 0b00000001; //set the 0th bit to 1
    else
        _sr._value = _sr._value & 0b11111110; //set the 0th bit to 0
}

void MOS6502::setOverflowFlag(bool value)
{
    if (value)
        _sr._value = _sr._value | 0b01000000; //set the 6th bit to 1
    else
        _sr._value = _sr._value & 0b10111111; //set the 6th bit to 0
}

void MOS6502::setMemory(uint16_t address, unsigned char value)
{
    if (address > 0xFFFF || address < 0x0000) {
        std::cerr << "SetMemory: Invalid address at " << address << std::endl;
        return;
    }
    if (value > 0xFF || value < 0x00) {
        std::cerr << "SetMemory: Invalid value: " << value << std::endl;
        return;
    }
    _memory[address].set(value);
}

unsigned char MOS6502::getMemory(uint16_t address, int &cycles)
{
    if (address > 0xFFFF || address < 0x0000) {
        std::cerr << "GetMemory: Invalid address at " << address << std::endl;
        return 0;
    }
    cycles--;
    return _memory[address]._value;
}

void MOS6502::setMemory(uint16_t address, unsigned char value, int &cycles)
{
    if (address > 0xFFFF || address < 0x0000) {
        std::cerr << "SetMemory: Invalid address at " << address << std::endl;
        return;
    }
    _memory[address].set(value);
    cycles--;
}
