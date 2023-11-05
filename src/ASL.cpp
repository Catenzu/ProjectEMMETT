/*
** EPITECH PROJECT, 2023
** ASL.cpp$
** File description:
** ASL.cpp$
*/

#include "../include/emmett.h"

void MOS6502::ASL_ACC(int &cycles)
{
    int value = _a._value;
    int result = value << 1;
    cycles--;

    // Set carry flag
    if (value & 0b10000000)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    _a.set(result);
    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    std::cout << "--ASL Accumulator: " << (int) _a._value << std::endl;
}

void MOS6502::ASL_ZERO(int &cycles)
{
    uint16_t address = getAdressZeroPage(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value << 1;
    cycles--;

    // Set carry flag
    if (value & 0b10000000)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlagFromByte(result);
    std::cout << "--ASL Zero Page: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::ASL_ZEROX(int &cycles)
{
    uint16_t address = getAdressZeroPageX(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value << 1;
    cycles--;

    // Set carry flag
    if (value & 0b10000000)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlagFromByte(result);
    std::cout << "--ASL Zero Page X: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::ASL_ABS(int &cycles)
{
    uint16_t address = getAdressAbsolute(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value << 1;
    cycles--;

    // Set carry flag
    if (value & 0b10000000)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlagFromByte(result);
    std::cout << "--ASL Absolute: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::ASL_ABSX(int &cycles)
{
    uint16_t address = getAdressAbsolute(cycles);
    address += _x._value;
    cycles--;
    unsigned char value = getMemory(address, cycles);
    int result = value << 1;
    cycles--;

    // Set carry flag
    if (value & 0b10000000)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlagFromByte(result);
    std::cout << "--ASL Absolute X: " << (int) _memory[address]._value << std::endl;
}