/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::LDA_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);

    _a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Immediate: " << (int) _a._value << std::endl;
}

void MOS6502::LDA_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);

    _a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Zero Page: " << (int) _a._value << std::endl;
}

void MOS6502::LDA_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles);

    _a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA ZeroX Page: " << (int) _a._value << std::endl;
}

void MOS6502::LDA_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);

    _a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Absolute: " << (int) _a._value << std::endl;
}

void MOS6502::LDA_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles);

    _a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Absolute X: " << (int) _a._value << std::endl;
}

void MOS6502::LDA_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles);

    _a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Absolute Y: " << (int) _a._value << std::endl;
}

void MOS6502::LDA_INDX(int &cycles)
{
    unsigned char value = getValueIndirectX(cycles);

    _a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Indirect X: " << (int) _a._value << std::endl;
}

void MOS6502::LDA_INDY(int &cycles)
{
    unsigned char value = getValueIndirectY(cycles);

    _a.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDA Indirect Y: " << (int) _a._value << std::endl;
}