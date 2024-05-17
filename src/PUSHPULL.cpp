/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::PHA(int &cycles)
{
    uint16_t address = 0x0100 + _sp._value;
    setMemory(address, _a._value,cycles); //1cycle
    _sp._value--;
    cycles--;

    if (_debugPrint)
        std::cout << "--PHA: " << (int) _sp._value << std::endl;
}

void MOS6502::PHP(int &cycles)
{
    uint16_t address = 0x0100 + _sp._value;
    setMemory(address, _sr._value,cycles); //1cycle
    _sp._value--;
    cycles--;

    if (_debugPrint)
        std::cout << "--PHP: " << (int) _sp._value << std::endl;
}

void MOS6502::PLA(int &cycles)
{
    _sp._value++;
    uint16_t address = 0x0100 + _sp._value;
    _a._value = getMemory(address,cycles); //1cycle
    cycles--;
    cycles--;

    if (_debugPrint)
        std::cout << "--PLA: " << (int) _sp._value << std::endl;
}

void MOS6502::PLP(int &cycles)
{
    _sp._value++;
    uint16_t address = 0x0100 + _sp._value;
    _sr._value = getMemory(address,cycles); //1cycle
    cycles--;
    cycles--;

    if (_debugPrint)
        std::cout << "--PLP: " << (int) _sp._value << std::endl;
}
