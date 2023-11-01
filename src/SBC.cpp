/*
** EPITECH PROJECT, 2023
** ADC.cpp$
** File description:
** ADC.cpp$
*/

#include <bitset>
#include "../include/emmett.h"

void MOS6502::SBC_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + ~value + 1 - (carry ? 0 : 1);
    unsigned char result8 =  result & 0xFF;

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setOverflowFlag(((_a._value ^ result8) & 0x80) && ((_a._value ^ result8) & 0x80));
    setCarryFlag(result < 0x100);

    //if decimal

    _a.set(result8);

    std::cout << "--SBC IM: " << (int) _a._value << std::endl;
}
