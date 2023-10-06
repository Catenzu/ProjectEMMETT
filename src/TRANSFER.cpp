/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::TAX(int &cycles)
{
    _x._value = _a._value;
    cycles--;

    setNegativeFlag(_x._value);
    setZeroFlag(_x._value);
    std::cout << "--TAX: " << (int) _x._value << std::endl;
}

void MOS6502::TAY(int &cycles)
{
    _y._value = _a._value;
    cycles--;

    setNegativeFlag(_y._value);
    setZeroFlag(_y._value);
    std::cout << "--TAY: " << (int) _y._value << std::endl;
}

void MOS6502::TXA(int &cycles)
{
    _a._value = _x._value;
    cycles--;

    setNegativeFlag(_a._value);
    setZeroFlag(_a._value);
    std::cout << "--TXA: " << (int) _a._value << std::endl;
}

void MOS6502::TYA(int &cycles)
{
    _a._value = _y._value;
    cycles--;

    setNegativeFlag(_a._value);
    setZeroFlag(_a._value);
    std::cout << "--TYA: " << (int) _a._value << std::endl;
}

void MOS6502::TSX(int &cycles)
{
    _x._value = _sp._value;
    cycles--;

    setNegativeFlag(_x._value);
    setZeroFlag(_x._value);
    std::cout << "--TSX: " << (int) _x._value << std::endl;
}

void MOS6502::TXS(int &cycles)
{
    _sp._value = _x._value;
    cycles--;

    std::cout << "--TXS: " << (int) _sp._value << std::endl;
}
