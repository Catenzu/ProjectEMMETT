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
