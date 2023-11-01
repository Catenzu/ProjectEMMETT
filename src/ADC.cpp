/*
** EPITECH PROJECT, 2023
** ADC.cpp$
** File description:
** ADC.cpp$
*/

#include "../include/emmett.h"

void MOS6502::ADC_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setCarryFlag(result > 0xFF);
    setOverflowFlag(((_a._value ^ value) & 0x80) && ((_a._value ^ result8) & 0x80));

    //if decimal


    _a.set(result8);
    std::cout << "--ADC IM: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlagFromByte(result8);
    setZeroFlagFromByte(result8);
    setCarryFlag(result > 0xFF);
    setOverflowFlag(((_a._value ^ value) & 0x80) && ((_a._value ^ result8) & 0x80));
    _a.set(result8);
    std::cout << "--ADC ZERO: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles);
    unsigned char carry = _sr._value & 0b00000001;
    unsigned char result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carrcycles--;

    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    setCarryFlag(result > 0xFF);
    setOverflowFlag(((_a._value ^ value) & 0x80) && ((_a._value ^ result8) & 0x80));
    _a.set(result8);
    std::cout << "--ADC ZEROX: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_ABS(int &cycles) //ne fonctionne pas correctement je sais pas pourquoi
{
    unsigned char value = getValueAbsolute(cycles);
    unsigned char carry = _sr._value & 0b00000001;
    unsigned char result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    setCarryFlag(result > 0xFF);
    setOverflowFlag(((_a._value ^ value) & 0x80) && ((_a._value ^ result8) & 0x80));
    _a.set(result8);
    std::cout << "--ADC ABS: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles);
    unsigned char carry = _sr._value & 0b00000001;
    unsigned char result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    setCarryFlag(result > 0xFF);
    setOverflowFlag(((_a._value ^ value) & 0x80) && ((_a._value ^ result8) & 0x80));
    _a.set(result8);
    std::cout << "--ADC ABSX: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles);
    unsigned char carry = _sr._value & 0b00000001;
    unsigned char result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    setCarryFlag(result > 0xFF);
    setOverflowFlag(((_a._value ^ value) & 0x80) && ((_a._value ^ result8) & 0x80));
    _a.set(result8);
    std::cout << "--ADC ABSY: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_INDX(int &cycles)
{
    unsigned char value = getValueIndirectX(cycles);

    unsigned char carry = _sr._value & 0b00000001;
    unsigned char result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    setCarryFlag(result > 0xFF);
    setOverflowFlag(((_a._value ^ value) & 0x80) && ((_a._value ^ result8) & 0x80));
    _a.set(result8);
    std::cout << "--ADC INDX: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_INDY(int &cycles)
{
    unsigned char value = getValueIndirectY(cycles);

    unsigned char carry = _sr._value & 0b00000001;
    unsigned char result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    if (result > 0xFF) //if the result is bigger than 255
        _sr._value = _sr._value | 0b00000001; //set the 0th bit to 1
    else
        _sr._value = _sr._value & 0b11111110;
    //overflow check
    if ((_a._value ^ value) & 0x80 && (_a._value ^ result & 0x80)) //if the sign of the two values is different and the sign of the two values and the result is different
        _sr._value = _sr._value | 0b01000000; //set the 6th bit to 1
    else
        _sr._value = _sr._value & 0b10111111;
    _a.set(result8);
    std::cout << "--ADC INDY: " << (int) _a._value << std::endl;
}