/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::STX_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    setMemory(address, _x._value,cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STX Zero Page: " << (int) _x._value << std::endl;
}

void MOS6502::STX_ZEROY(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char yV = _y._value;
    address = aluAddition(address, yV, cycles); //1cycle
    setMemory(address, _x._value,cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STX ZeroY Page: " << (int) _x._value << std::endl;
}

void MOS6502::STX_ABS(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char adress2 = fetch(cycles); //1cycle
    uint16_t address = ((uint16_t)adress2 * 256) + (uint16_t)address1;
    setMemory(address, _x._value, cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STX Absolute: " << (int) _x._value << std::endl;
}

