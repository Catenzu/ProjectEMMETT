/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::LDA_IM(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle

    a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Immediate: " << (int) a._value << std::endl;
}

void MOS6502::LDA_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char value = getMemory(address, cycles); //1cycle

    a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Zero Page: " << (int) a._value << std::endl;
}

void MOS6502::LDA_ZEROX(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char xV = fetchX(cycles); //1cycle
    address += xV;
    unsigned char value = getMemory(address, cycles); //1cycle

    a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA ZeroX Page: " << (int) a._value << std::endl;
}

void MOS6502::LDA_ABS(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char adress2 = fetch(cycles); //1cycle
    uint16_t address = ((uint16_t)adress2 * 256) + (uint16_t)address1;
    unsigned char value = getMemory(address, cycles); //1cycle

    a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Absolute Page: " << (int) a._value << std::endl;
}