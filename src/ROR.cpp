/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::ROR_ACC(int &cycles)
{
    int value = _a._value;
    int result = value >> 1;
    cycles--;

    // get carry flag
    if (_sr._value & 0b00000001)
        result |= 0b10000000;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    _a.set(result);
    setNegativeFlag(result);
    setZeroFlag(result);
    std::cout << "--ROR Accumulator: " << (int) _a._value << std::endl;
}

void MOS6502::ROR_ZERO(int &cycles)
{
    uint16_t address = getAdressZeroPage(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value >> 1;
    cycles--;

    // get carry flag
    if (_sr._value & 0b00000001)
        result |= 0b10000000;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlag(result);
    std::cout << "--ROR Zero Page: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::ROR_ZEROX(int &cycles)
{
    uint16_t address = getAdressZeroPageX(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value >> 1;
    cycles--;

    // get carry flag
    if (_sr._value & 0b00000001)
        result |= 0b10000000;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlag(result);
    std::cout << "--ROR Zero Page X: " << (int) _a._value << std::endl;
}

void MOS6502::ROR_ABS(int &cycles)
{
    uint16_t address = getAdressAbsolute(cycles);
    unsigned char value = getMemory(address, cycles);
    int result = value >> 1;
    cycles--;

    // get carry flag
    if (_sr._value & 0b00000001)
        result |= 0b10000000;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlag(result);
    std::cout << "--ROR Absolute: " << (int) _a._value << std::endl;
}

void MOS6502::ROR_ABSX(int &cycles)
{
    uint16_t address = getAdressAbsolute(cycles);
    address += _x._value;
    cycles--;
    unsigned char value = getMemory(address, cycles);
    int result = value >> 1;
    cycles--;

    // get carry flag
    if (_sr._value & 0b00000001)
        result |= 0b10000000;

    // Set carry flag
    if (value & 0b00000001)
        _sr._value |= 0b00000001;
    else
        _sr._value &= 0b11111110;

    setMemory(address, result, cycles);
    setNegativeFlag(result);
    std::cout << "--ROR Absolute X: " << (int) _a._value << std::endl;
}
