/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::LDX_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);

    _x.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDX Immediate: " << (int) _x._value << std::endl;
}

void MOS6502::LDX_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);

    _x.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDX Zero Page: " << (int) _x._value << std::endl;
}

void MOS6502::LDX_ZEROY(int &cycles)
{
    unsigned char value = getValueZeroPageY(cycles);

    _x.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDX ZeroY Page: " << (int) _x._value << std::endl;
}

void MOS6502::LDX_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);

    _x.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDX Absolute: " << (int) _x._value << std::endl;
}

void MOS6502::LDX_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles);

    _x.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDX Absolute Y: " << (int) _x._value << std::endl;
}