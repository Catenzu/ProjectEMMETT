/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::CPX_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);

    if (_x._value >= value) //CARRY IF X >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_x._value == value) //ZERO IF X == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _x._value - value;
    setNegativeFlagFromByte(result);
    if (_debugPrint)
        std::cout << "--CPX Immediate: " << (int) result << std::endl;
}

void MOS6502::CPX_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);

    if (_x._value >= value) //CARRY IF X >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_x._value == value) //ZERO IF X == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _x._value - value;
    setNegativeFlagFromByte(result);
    if (_debugPrint)
        std::cout << "--CPX Zero Page: " << (int) result << std::endl;
}

void MOS6502::CPX_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);

    if (_x._value >= value) //CARRY IF X >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_x._value == value) //ZERO IF X == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _x._value - value;
    setNegativeFlagFromByte(result);
    if (_debugPrint)
        std::cout << "--CPX Absolute: " << (int) result << std::endl;
}
