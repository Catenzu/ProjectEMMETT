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
    unsigned char carry = sr._value & 0b00000001;
    uint16_t result = a._value + value + carry; //addition of the two values and the carry
    unsigned char result8 = a._value + value + carry; //addition of the two values and the carry

    setNegativeFlag(result);
    setZeroFlag(result);
    if (result > 0xFF) //if the result is bigger than 255
        sr._value = sr._value | 0b00000001; //set the 0th bit to 1
    //overflow check
    if (a._value ^ value & 0x80 && a._value ^ result & 0x80) //if the sign of the two values is different and the sign of the two values and the result is different
        sr._value = sr._value | 0b01000000; //set the 6th bit to 1

    a.set(result8);
    std::cout << "ADC: " << (int) a._value << std::endl;
}

void MOS6502::ADC_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles);
    unsigned char value = getMemory(address, cycles);
    unsigned char carry = sr._value & 0b00000001;
    unsigned char result = a._value + value + carry; //addition of the two values and the carry

    if (result == 0)
        sr._value = sr._value | 0b00000010; //set the 7th bit to 1
    if (result & 0b10000000) //if the 7th bit is 1
        sr._value = sr._value | 0b10000000; //set the 0th bit to 1
    if (result > 0xFF) //if the result is bigger than 255
        sr._value = sr._value | 0b00000001; //set the 0th bit to 1
    //overflow check
    if ((a._value ^ value) & 0x80 && (a._value ^ result & 0x80)) //if the sign of the two values is different and the sign of the two values and the result is different
        sr._value = sr._value | 0b01000000; //set the 6th bit to 1
    a.set(result);
    std::cout << "ADC ZERO: " << (int) a._value << std::endl;
}

void MOS6502::ADC_ZEROX(int &cycles)
{
    unsigned char address = fetch(cycles);
}

void MOS6502::ADC_ABS(int &cycles)
{

}
