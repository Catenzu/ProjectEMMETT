/*
** EPITECH PROJECT, 2023
** ADC.cpp$
** File description:
** ADC.cpp$
*/

#include "../include/emmett.h"

void MOS6502::ADC_IM(int &cycles)
{
    unsigned char value = fetch(cycles); // 1cycle
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlag(result8);
    setZeroFlag(result8);
    if (result > 0xFF) //if the result is bigger than 255
        _sr._value = _sr._value | 0b00000001; //set the 0th bit to 1
    //overflow check
    if (_a._value ^ value & 0x80 && _a._value ^ result8 & 0x80) //if the sign of the two values is different and the sign of the two values and the result is different
        _sr._value = _sr._value | 0b01000000; //set the 6th bit to 1

    _a.set(result8);
    std::cout << "--ADC: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles);
    unsigned char value = getMemory(address, cycles);
    unsigned char carry = _sr._value & 0b00000001;
    uint16_t result = _a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = _a._value + value + carry; //addition of the two values and the carry

    setNegativeFlag(result8);
    setZeroFlag(result8);
    if (result > 0xFF) //if the result is bigger than 255
        _sr._value = _sr._value | 0b00000001; //set the 0th bit to 1
    //overflow check
    if (_a._value ^ value & 0x80 && _a._value ^ result8 & 0x80) //if the sign of the two values is different and the sign of the two values and the result is different
        _sr._value = _sr._value | 0b01000000; //set the 6th bit to 1
    _a.set(result8);
    std::cout << "--ADC ZERO: " << (int) _a._value << std::endl;
}

void MOS6502::ADC_ZEROX(int &cycles)
{
    unsigned char address = fetch(cycles);
    address += x._value;

    unsigned char value = getMemory(address, cycles);
    unsigned char carry = sr._value & 0b00000001;
    unsigned char result = a._value + value + carry; //addition of the two values and the carry

    setNegativeFlag(value);
    setZeroFlag(value);
    if (result > 0xFF) //if the result is bigger than 255
        sr._value = sr._value | 0b00000001; //set the 0th bit to 1
    //overflow check
    if ((a._value ^ value) & 0x80 && (a._value ^ result & 0x80)) //if the sign of the two values is different and the sign of the two values and the result is different
        sr._value = sr._value | 0b01000000; //set the 6th bit to 1
    a.set(result);
    std::cout << "ADC ZEROX: " << (int) a._value << std::endl;
}

void MOS6502::ADC_ABS(int &cycles) //ne fonctionne pas correctement je sais pas pourquoi
{
    unsigned char address1 = fetch(cycles);
    unsigned char address2 = fetch(cycles);
    uint16_t address = ((uint16_t)address2 * 256) + (uint16_t)address1;

    unsigned char value = getMemory(address, cycles);
    unsigned char carry = sr._value & 0b00000001;
    unsigned char result = a._value + value + carry; //addition of the two values and the carry

    setNegativeFlag(value);
    setZeroFlag(value);
    if (result > 0xFF) //if the result is bigger than 255
        sr._value = sr._value | 0b00000001; //set the 0th bit to 1
    //overflow check
    if ((a._value ^ value) & 0x80 && (a._value ^ result & 0x80)) //if the sign of the two values is different and the sign of the two values and the result is different
        sr._value = sr._value | 0b01000000; //set the 6th bit to 1
    a.set(result);
    std::cout << "ADC ABS: " << (int) a._value << std::endl;
}
