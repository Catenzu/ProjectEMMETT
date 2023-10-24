/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::ROR_ACC(int &cycles)
{
    std::cout << "--ROR Accumulator: " << (int) _a._value << std::endl;
}

void MOS6502::ROR_ZERO(int &cycles)
{
    std::cout << "--ROR Zero Page: " << (int) _a._value << std::endl;
}

void MOS6502::ROR_ZEROX(int &cycles)
{
    std::cout << "--ROR Zero Page X: " << (int) _a._value << std::endl;
}

void MOS6502::ROR_ABS(int &cycles)
{
    std::cout << "--ROR Absolute: " << (int) _a._value << std::endl;
}

void MOS6502::ROR_ABSX(int &cycles)
{
    std::cout << "--ROR Absolute X: " << (int) _a._value << std::endl;
}
