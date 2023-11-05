/*
** EPITECH PROJECT, 2023
** AND.cpp$
** File description:
** AND.cpp$
*/

#include "../include/emmett.h"

void MOS6502::EOR_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);
    unsigned char result = _a._value ^ value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--EOR: " << (int) _a._value << std::endl;
}

void MOS6502::EOR_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);
    unsigned char result = _a._value ^ value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--EOR ZERO: " << (int) _a._value << std::endl;
}

void MOS6502::EOR_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles);
    unsigned char result = _a._value ^ value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--EOR ZEROX: " << (int) _a._value << std::endl;
}

void MOS6502::EOR_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);
    unsigned char result = _a._value ^ value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--EOR ABS: " << (int) _a._value << std::endl;
}

void MOS6502::EOR_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles);
    unsigned char result = _a._value ^ value;

    setZeroFlagFromByte(result);
    setNegativeFlagFromByte(result);
    _a.set(result);
    std::cout << "--EOR ABSX: " << (int) _a._value << std::endl;
}

void MOS6502::EOR_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles);
    unsigned char result = _a._value ^ value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--EOR ABSY: " << (int) _a._value << std::endl;
}

void MOS6502::EOR_INDX(int &cycles)
{
    unsigned char value = getValueIndirectX(cycles);
    unsigned char result = _a._value ^ value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--EOR Indirect X: " << (int) _a._value << std::endl;
}

void MOS6502::EOR_INDY(int &cycles)
{
    unsigned char value = getValueIndirectY(cycles);
    unsigned char result = _a._value ^ value;

    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    _a.set(result);
    std::cout << "--EOR Indirect Y: " << (int) _a._value << std::endl;
}