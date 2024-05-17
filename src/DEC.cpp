/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::DEC_ABS(int &cycles)
{
    uint16_t address = getAdressAbsolute(cycles);
    unsigned char value = _memory[address]._value; cycles -= 3;

    value--;
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    _memory[address]._value = value;
    if (_debugPrint)
        std::cout << "--DEC ABS: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::DEC_ABSX(int &cycles)
{
    uint16_t address = getAdressAbsoluteX(cycles);
    unsigned char value = _memory[address]._value; cycles -= 4;

    value--;
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    _memory[address]._value = value;
    if (_debugPrint)
        std::cout << "--DEC ABSX: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::DEC_ZERO(int &cycles)
{
    uint16_t address = getAdressZeroPage(cycles);
    unsigned char value = _memory[address]._value; cycles -= 2;

    value--;
    cycles--;
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    _memory[address]._value = value;
    if (_debugPrint)
        std::cout << "--DEC ZERO: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::DEC_ZEROX(int &cycles)
{
    uint16_t address = getAdressZeroPageX(cycles);
    unsigned char value = _memory[address]._value; cycles -= 3;

    value--;
    setNegativeFlagFromByte(value);
    setZeroFlagFromByte(value);
    _memory[address]._value = value;
    if (_debugPrint)
        std::cout << "--DEC ZEROX: " << (int) _memory[address]._value << std::endl;
}

void MOS6502::DEX(int &cycles)
{
    _x.set(_x._value - 1);
    cycles--;
    setNegativeFlagFromByte(_x._value);
    setZeroFlagFromByte(_x._value);
    if (_debugPrint)
        std::cout << "--DEX: " << (int) _x._value << std::endl;
}

void MOS6502::DEY(int &cycles)
{
    _y.set(_y._value - 1);
    cycles--;
    setNegativeFlagFromByte(_y._value);
    setZeroFlagFromByte(_y._value);
    if (_debugPrint)
        std::cout << "--DEY: " << (int) _y._value << std::endl;
}