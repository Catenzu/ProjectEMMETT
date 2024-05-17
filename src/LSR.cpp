/*
** EPITECH PROJECT, 2023
** ASL.cpp$
** File description:
** ASL.cpp$
*/

#include "../include/emmett.h"

void MOS6502::LSR_ACC(int &cycles)
{
    int value = _a._value;
    int result = value >> 1;
    cycles--;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    _a.set(result);
    setNegativeFlagFromByte(result);
    setZeroFlagFromByte(result);
    if (_debugPrint)
        std::cout << "--LSR Accumulator: " << (int) _a._value << std::endl;
}

void MOS6502::LSR_ZERO(int &cycles)
{
    uint16_t address = getAdressZeroPage(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value >> 1;
    cycles--;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlagFromByte(result);
    if (_debugPrint)
        std::cout << "--LSR Zero Page: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::LSR_ZEROX(int &cycles)
{
    uint16_t address = getAdressZeroPageX(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value >> 1;
    cycles--;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlagFromByte(result);
    if (_debugPrint)
        std::cout << "--LSR Zero Page X: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::LSR_ABS(int &cycles)
{
    uint16_t address = getAdressAbsolute(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value >> 1;
    cycles--;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlagFromByte(result);
    if (_debugPrint)
        std::cout << "--LSR Absolute: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::LSR_ABSX(int &cycles)
{
    uint16_t address = getAdressAbsolute(cycles);
    address += _x._value;
    cycles--;
    unsigned char value = getMemory(address, cycles);
    int result = value >> 1;
    cycles--;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlagFromByte(result);
    if (_debugPrint)
        std::cout << "--LSR Absolute X: " << (int) _memory[address]._value << std::endl;
}