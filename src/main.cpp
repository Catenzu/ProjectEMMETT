/*
 * Emmett
 */

#include "../include/emmett.h"

int main()
{
    MOS6502 cpu;
    Register a;

    a.set(0xFF);
    std::cout << (int) a._value << std::endl;
    a.set(0b00001010);
    std::cout << (int) a._value << std::endl;
    a.set(0b11111111);
    std::cout << (int) a._value << std::endl;

    uint16_t address = 0xFFFF;
    std::cout << address << std::endl;

    cpu.setMemory(address, 0xFF);
    std::cout << cpu.memory[address]._value << std::endl;
    return 0;
}