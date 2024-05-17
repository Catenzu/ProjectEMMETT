/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::BIT_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);
    unsigned char result = _a._value & value;

    setZeroFlag(!result);
    setNegativeFlag(result & 0b10000000);
    setOverflowFlag(value & 0b01000000);
    if (_debugPrint)
        std::cout << "--BIT_ABS: " << std::bitset<8>(result) << std::endl;
}

void MOS6502::BIT_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);
    unsigned char result = _a._value & value;

    setZeroFlag(!result);
    setNegativeFlag(result & 0b10000000);
    setOverflowFlag(value & 0b01000000);
    if (_debugPrint)
        std::cout << "--BIT_ABS: " << std::bitset<8>(result) << std::endl;
}
