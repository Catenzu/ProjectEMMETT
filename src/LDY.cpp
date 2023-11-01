/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::LDY_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);

    _y.set(value);
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    std::cout << "--LDY Immediate: " << (int) _y._value << std::endl;
}

void MOS6502::LDY_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);

    _y.set(value);
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    std::cout << "--LDY Zero Page: " << (int) _y._value << std::endl;
}

void MOS6502::LDY_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles);

    _y.set(value);
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    std::cout << "--LDY ZeroY Page: " << (int) _y._value << std::endl;
}

void MOS6502::LDY_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);

    _y.set(value);
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    std::cout << "--LDY Absolute: " << (int) _y._value << std::endl;
}

void MOS6502::LDY_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles);

    _y.set(value);
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    std::cout << "--LDY Absolute X: " << (int) _y._value << std::endl;
}