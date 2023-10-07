/*
** EPITECH PROJECT, 2023
** ASL.cpp$
** File description:
** ASL.cpp$
*/

#include "../include/emmett.h"

void MOS6502::ASL_ACC(int &cycles)
{
    unsigned char result = _a._value << 1;

    cycles--;
    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "ASL ACC: " << (int) _a._value << std::endl;
}

void MOS6502::ASL_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles);
    unsigned char value = getMemory(address, cycles);
    bool carry = (value & 0x80) != 0;

    value <<= 1;
    setZeroFlag(value);
    setNegativeFlag(value);
    if (carry) {
        _sr._value |= 0b00000001;
    } else {
        _sr._value &= 0b11111110;
    }
    setMemory(address, value);
    cycles-=2;
    std::cout << "ASL ZERO: " << (int)value << std::endl;
}

void MOS6502::ASL_ZEROX(int &cycles)
{

}

void MOS6502::ASL_ABS(int &cycles)
{

}

void MOS6502::ASL_ABSX(int &cycles)
{

}
