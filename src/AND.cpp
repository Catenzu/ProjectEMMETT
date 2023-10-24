/*
** EPITECH PROJECT, 2023
** AND.cpp$
** File description:
** AND.cpp$
*/

#include "../include/emmett.h"

void MOS6502::AND_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND ZERO: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND ZEROX: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND ABS: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles);
    unsigned char result = _a._value & value;

    setZeroFlag(result);
    setNegativeFlag(result);
    _a.set(result);
    std::cout << "--AND ABSX: " << (int) _a._value << std::endl;
}

void MOS6502::AND_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND ABSY: " << (int) _a._value << std::endl;
}

void MOS6502::AND_INDX(int &cycles)
{
    unsigned char value = getValueIndirectX(cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND Indirect X: " << (int) _a._value << std::endl;
}

void MOS6502::AND_INDY(int &cycles)
{
    unsigned char value = getValueIndirectY(cycles);
    unsigned char result = _a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    _a.set(result);
    std::cout << "--AND Indirect Y: " << (int) _a._value << std::endl;
}