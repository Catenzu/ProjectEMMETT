/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::CMP_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);

    if (_a._value >= value) //CARRY IF A >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_a._value == value) //ZERO IF A == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _a._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CMP Immediate: " << (int) result << std::endl;
}

void MOS6502::CMP_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);

    if (_a._value >= value) //CARRY IF A >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_a._value == value) //ZERO IF A == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _a._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CMP Zero Page: " << (int) result << std::endl;
}

void MOS6502::CMP_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles);

    if (_a._value >= value) //CARRY IF A >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_a._value == value) //ZERO IF A == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _a._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CMP ZeroX Page: " << (int) result << std::endl;
}

void MOS6502::CMP_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);

    if (_a._value >= value) //CARRY IF A >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_a._value == value) //ZERO IF A == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _a._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CMP Absolute: " << (int) result << std::endl;
}

void MOS6502::CMP_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles);

    if (_a._value >= value) //CARRY IF A >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_a._value == value) //ZERO IF A == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _a._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CMP Absolute X: " << (int) result << std::endl;
}

void MOS6502::CMP_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles);

    if (_a._value >= value) //CARRY IF A >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_a._value == value) //ZERO IF A == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _a._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CMP Absolute Y: " << (int) result << std::endl;
}

void MOS6502::CMP_INDX(int &cycles)
{
    unsigned char value = getValueIndirectX(cycles);

    if (_a._value >= value) //CARRY IF A >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_a._value == value) //ZERO IF A == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _a._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CMP Indirect X: " << (int) result << std::endl;
}

void MOS6502::CMP_INDY(int &cycles)
{
    unsigned char value = getValueIndirectY(cycles);

    _a.set(value);
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);if (_a._value >= value) //CARRY IF A >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_a._value == value) //ZERO IF A == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _a._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CMP Indirect Y: " << (int) result << std::endl;
}