/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::ROL_ACC(int &cycles)
{
    int value = _a._value;
    int result = value << 1;
    cycles--;

    // get carry flag
    if (_sr._value & 0b00000001)
        result |= 0b00000001;

    // Set carry flag
    if (value & 0b10000000)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    _a.set(result);
    setNegativeFlag(result);
    setZeroFlag(result);
    std::cout << "--ROL Accumulator: " << (int) _a._value << std::endl;
}

void MOS6502::ROL_ZERO(int &cycles)
{
    std::cout << "--ROL Zero Page: " << (int) _a._value << std::endl;
}

void MOS6502::ROL_ZEROX(int &cycles)
{
    std::cout << "--ROL Zero Page X: " << (int) _a._value << std::endl;
}

void MOS6502::ROL_ABS(int &cycles)
{
    std::cout << "--ROL Absolute: " << (int) _a._value << std::endl;
}

void MOS6502::ROL_ABSX(int &cycles)
{
    std::cout << "--ROL Absolute X: " << (int) _a._value << std::endl;
}
