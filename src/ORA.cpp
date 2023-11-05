/*
** EPITECH PROJECT, 2023
** AND.cpp$
** File description:
** AND.cpp$
*/

#include "../include/emmett.h"

void MOS6502::ORA_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);
    unsigned char result = _a._value | value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--ORA: " << (int) _a._value << std::endl;
}

void MOS6502::ORA_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);
    unsigned char result = _a._value | value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--ORA ZERO: " << (int) _a._value << std::endl;
}

void MOS6502::ORA_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles);
    unsigned char result = _a._value | value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--ORA ZEROX: " << (int) _a._value << std::endl;
}

void MOS6502::ORA_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);
    unsigned char result = _a._value | value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--ORA ABS: " << (int) _a._value << std::endl;
}

void MOS6502::ORA_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles);
    unsigned char result = _a._value | value;

    setZeroFlagFromByte(result);
    setNegativeFlagFromByte(result);
    _a.set(result);
    std::cout << "--ORA ABSX: " << (int) _a._value << std::endl;
}

void MOS6502::ORA_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles);
    unsigned char result = _a._value | value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--ORA ABSY: " << (int) _a._value << std::endl;
}

void MOS6502::ORA_INDX(int &cycles)
{
    unsigned char value = getValueIndirectX(cycles);
    unsigned char result = _a._value | value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--ORA Indirect X: " << (int) _a._value << std::endl;
}

void MOS6502::ORA_INDY(int &cycles)
{
    unsigned char value = getValueIndirectY(cycles);
    unsigned char result = _a._value | value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--ORA Indirect Y: " << (int) _a._value << std::endl;
}