/*
** EPITECH PROJECT, 2023
** AND.cpp$
** File description:
** AND.cpp$
*/

#include "../include/emmett.h"

void MOS6502::AND_IM(int &cycles)
{
    unsigned char value = fetch(cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles);
    unsigned char value = getMemory(address, cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND ZERO: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ZEROX(int &cycles)
{
    unsigned char address = fetch(cycles);
    address += _x._value;
    unsigned char value = getMemory(address, cycles);
    unsigned char result = _a._value & value;
    cycles--;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND ZEROX: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ABS(int &cycles)
{
    uint16_t address = fetch(cycles);
    unsigned char value = getMemory(address, cycles);
    unsigned char result = _a._value & value;
    cycles--;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND ABS: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ABSX(int &cycles)
{
    unsigned char addressLow = fetch(cycles);
    unsigned char addressHigh = fetch(cycles);
    uint16_t address = ((uint16_t)addressHigh * 256) + (uint16_t)addressLow;
    address += _x._value;
    bool pageCrossed = (address & 0xFF00) != (addressHigh << 8);
    unsigned char value = getMemory(address, cycles);
    unsigned char result = _a._value & value;

    setZeroFlag(result);
    setNegativeFlag(result);
    _a.set(result);
    if (pageCrossed)
        cycles++;
    std::cout << "--AND ABSX: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ABSY(int &cycles)
{
    uint16_t address = fetch(cycles);
    address += _y._value;
    unsigned char value = getMemory(address, cycles);
    unsigned char result = _a._value & value;
    cycles--;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND ABSY: " << (int) _a._value << std::endl;
}

void MOS6502::AND_INDX(int &cycles)
{

}

void MOS6502::AND_INDY(int &cycles)
{

}