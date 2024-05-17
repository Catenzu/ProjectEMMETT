/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::TAX(int &cycles)
{
    _x._value = _a._value;
    cycles--;

    setNegativeFlagFromByte(_x._value);
    setZeroFlagFromByte(_x._value);
    if (_debugPrint)
        std::cout << "--TAX: " << (int) _x._value << std::endl;
}

void MOS6502::TAY(int &cycles)
{
    _y._value = _a._value;
    cycles--;

    setNegativeFlagFromByte(_y._value);
    setZeroFlagFromByte(_y._value);
    if (_debugPrint)
        std::cout << "--TAY: " << (int) _y._value << std::endl;
}

void MOS6502::TXA(int &cycles)
{
    _a._value = _x._value;
    cycles--;

    setNegativeFlagFromByte(_a._value);
    setZeroFlagFromByte(_a._value);
    if (_debugPrint)
        std::cout << "--TXA: " << (int) _a._value << std::endl;
}

void MOS6502::TYA(int &cycles)
{
    _a._value = _y._value;
    cycles--;

    setNegativeFlagFromByte(_a._value);
    setZeroFlagFromByte(_a._value);
    if (_debugPrint)
        std::cout << "--TYA: " << (int) _a._value << std::endl;
}

void MOS6502::TSX(int &cycles)
{
    _x._value = _sp._value;
    cycles--;

    setNegativeFlagFromByte(_x._value);
    setZeroFlagFromByte(_x._value);
    if (_debugPrint)
        std::cout << "--TSX: " << (int) _x._value << std::endl;
}

void MOS6502::TXS(int &cycles)
{
    _sp._value = _x._value;
    cycles--;

    if (_debugPrint)
        std::cout << "--TXS: " << (int) _sp._value << std::endl;
}
