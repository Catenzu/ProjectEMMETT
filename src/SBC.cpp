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
    if (_sr._value & 0b00001000)
    {
        if (((_a._value & 0x0F) - (_sr._value & 0b00000001 ? 0 : 1)) < (result8 & 0x0F))
            result -= 6;
        if (result > 0x99)
            result -= 0x60;
        result8 = result & 0xFF;
    }
    _a.set(result8);

    if (_debugPrint)
        std::cout << "--SBC IM: " << (int) _a._value << std::endl;
}

void MOS6502::SBC_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + ~value + 1 - (carry ? 0 : 1);
    unsigned char result8 =  result & 0xFF;

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setOverflowFlag(((_a._value ^ result8) & 0x80) && ((_a._value ^ result8) & 0x80));
    setCarryFlag(result < 0x100);

    //if decimal
    if (_sr._value & 0b00001000)
    {
        if (((_a._value & 0x0F) - (_sr._value & 0b00000001 ? 0 : 1)) < (result8 & 0x0F))
            result -= 6;
        if (result > 0x99)
            result -= 0x60;
        result8 = result & 0xFF;
    }
    _a.set(result8);

    if (_debugPrint)
        std::cout << "--SBC ZERO: " << (int) _a._value << std::endl;
}

void MOS6502::SBC_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + ~value + 1 - (carry ? 0 : 1);
    unsigned char result8 =  result & 0xFF;

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setOverflowFlag(((_a._value ^ result8) & 0x80) && ((_a._value ^ result8) & 0x80));
    setCarryFlag(result < 0x100);

    //if decimal
    if (_sr._value & 0b00001000)
    {
        if (((_a._value & 0x0F) - (_sr._value & 0b00000001 ? 0 : 1)) < (result8 & 0x0F))
            result -= 6;
        if (result > 0x99)
            result -= 0x60;
        result8 = result & 0xFF;
    }
    _a.set(result8);

    if (_debugPrint)
        std::cout << "--SBC ZEROX: " << (int) _a._value << std::endl;
}

void MOS6502::SBC_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + ~value + 1 - (carry ? 0 : 1);
    unsigned char result8 =  result & 0xFF;

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setOverflowFlag(((_a._value ^ result8) & 0x80) && ((_a._value ^ result8) & 0x80));
    setCarryFlag(result < 0x100);

    //if decimal
    if (_sr._value & 0b00001000)
    {
        if (((_a._value & 0x0F) - (_sr._value & 0b00000001 ? 0 : 1)) < (result8 & 0x0F))
            result -= 6;
        if (result > 0x99)
            result -= 0x60;
        result8 = result & 0xFF;
    }
    _a.set(result8);

    if (_debugPrint)
        std::cout << "--SBC ABS: " << (int) _a._value << std::endl;
}

void MOS6502::SBC_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + ~value + 1 - (carry ? 0 : 1);
    unsigned char result8 =  result & 0xFF;

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setOverflowFlag(((_a._value ^ result8) & 0x80) && ((_a._value ^ result8) & 0x80));
    setCarryFlag(result < 0x100);

    //if decimal
    if (_sr._value & 0b00001000)
    {
        if (((_a._value & 0x0F) - (_sr._value & 0b00000001 ? 0 : 1)) < (result8 & 0x0F))
            result -= 6;
        if (result > 0x99)
            result -= 0x60;
        result8 = result & 0xFF;
    }
    _a.set(result8);

    if (_debugPrint)
        std::cout << "--SBC ABSX: " << (int) _a._value << std::endl;
}

void MOS6502::SBC_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + ~value + 1 - (carry ? 0 : 1);
    unsigned char result8 =  result & 0xFF;

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setOverflowFlag(((_a._value ^ result8) & 0x80) && ((_a._value ^ result8) & 0x80));
    setCarryFlag(result < 0x100);

    //if decimal
    if (_sr._value & 0b00001000)
    {
        if (((_a._value & 0x0F) - (_sr._value & 0b00000001 ? 0 : 1)) < (result8 & 0x0F))
            result -= 6;
        if (result > 0x99)
            result -= 0x60;
        result8 = result & 0xFF;
    }
    _a.set(result8);

    if (_debugPrint)
        std::cout << "--SBC ABSY: " << (int) _a._value << std::endl;
}

void MOS6502::SBC_INDX(int &cycles)
{
    unsigned char value = getValueIndirectX(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + ~value + 1 - (carry ? 0 : 1);
    unsigned char result8 =  result & 0xFF;

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setOverflowFlag(((_a._value ^ result8) & 0x80) && ((_a._value ^ result8) & 0x80));
    setCarryFlag(result < 0x100);

    //if decimal
    if (_sr._value & 0b00001000)
    {
        if (((_a._value & 0x0F) - (_sr._value & 0b00000001 ? 0 : 1)) < (result8 & 0x0F))
            result -= 6;
        if (result > 0x99)
            result -= 0x60;
        result8 = result & 0xFF;
    }
    _a.set(result8);

    if (_debugPrint)
        std::cout << "--SBC INDX: " << (int) _a._value << std::endl;
}

void MOS6502::SBC_INDY(int &cycles)
{
    unsigned char value = getValueIndirectY(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + ~value + 1 - (carry ? 0 : 1);
    unsigned char result8 =  result & 0xFF;

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setOverflowFlag(((_a._value ^ result8) & 0x80) && ((_a._value ^ result8) & 0x80));
    setCarryFlag(result < 0x100);

    //if decimal
    if (_sr._value & 0b00001000)
    {
        if (((_a._value & 0x0F) - (_sr._value & 0b00000001 ? 0 : 1)) < (result8 & 0x0F))
            result -= 6;
        if (result > 0x99)
            result -= 0x60;
        result8 = result & 0xFF;
    }
    _a.set(result8);

    if (_debugPrint)
        std::cout << "--SBC INDY: " << (int) _a._value << std::endl;
}
