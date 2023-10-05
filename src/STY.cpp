/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::STY_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    setMemory(address, _y._value,cycles); //1cycle

    std::cout << "--STY Zero Page: " << (int) _y._value << std::endl;
}

void MOS6502::STY_ZEROX(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    address = aluAddition(address, xV, cycles); //1cycle
    setMemory(address, _y._value,cycles); //1cycle

    std::cout << "--STY ZeroX Page: " << (int) _y._value << std::endl;
}

void MOS6502::STY_ABS(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char adress2 = fetch(cycles); //1cycle
    uint16_t address = ((uint16_t)adress2 * 256) + (uint16_t)address1;
    setMemory(address, _y._value, cycles); //1cycle

    std::cout << "--STY Absolute: " << (int) _y._value << std::endl;
}

