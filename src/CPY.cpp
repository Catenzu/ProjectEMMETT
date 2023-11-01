/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::CPY_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);

    if (_y._value >= value) //CARRY IF Y >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_y._value == value) //ZERO IF Y == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _y._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CPY Immediate: " << (int) result << std::endl;
}

void MOS6502::CPY_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);

    if (_y._value >= value) //CARRY IF Y >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_y._value == value) //ZERO IF Y == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _y._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CPY Zero Page: " << (int) result << std::endl;
}

void MOS6502::CPY_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);

    if (_y._value >= value) //CARRY IF Y >= VALUE
        _sr.set(_sr._value | 0b00000001);
    else
        _sr.set(_sr._value & 0b11111110);

    if (_y._value == value) //ZERO IF Y == VALUE
        _sr.set(_sr._value | 0b00000010);
    else
        _sr.set(_sr._value & 0b11111101);

    unsigned char result = _y._value - value;
    setNegativeFlagFromByte(result);
    std::cout << "--CPY Absolute: " << (int) result << std::endl;
}
