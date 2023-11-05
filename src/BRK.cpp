/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::BRK(int &cycles)
{
    unsigned char low = getMemory(0xFFFE,cycles); //1cycle
    unsigned char high = getMemory(0xFFFF,cycles); //1cycle

    uint16_t address = ((uint16_t)high * 256) + (uint16_t)low;
    uint16_t pc = _pc - 1;
    auto pcLow = (unsigned char)(pc & 0xFF);
    auto pcHigh = (unsigned char)(pc >> 8);

    uint16_t addressStack = 0x0100 + _sp._value;
    setMemory(addressStack, pcHigh,cycles); //1cycle
    _sp._value--;
    addressStack = 0x0100 + _sp._value;
    setMemory(addressStack, pcLow,cycles); //1cycle
    _sp._value--;
    addressStack = 0x0100 + _sp._value;
    setMemory(addressStack, _sr._value,cycles); //1cycle
    _sp._value--;

    _sr._value |= 0b00010000;

    _pc = address;
    cycles--; //1cycle
    std::cout << "--BRK Absolute: " << (int) _pc << std::endl;
}

void MOS6502::RTI(int &cycles)
{
    _sp._value++;
    _sr._value = getMemory(0x0100 + _sp._value,cycles); //1cycle
    cycles--; //1cycle

    _sp._value++;
    unsigned char pcLow = getMemory(0x0100 + _sp._value,cycles); //1cycle
    cycles--; //1cycle

    _sp._value++;
    unsigned char pcHigh = getMemory(0x0100 + _sp._value,cycles); //1cycle

    uint16_t pc = ((uint16_t)pcHigh * 256) + (uint16_t)pcLow;
    _pc = pc + 1;

    std::cout << "--RTI: " << (int) _pc << std::endl;
}
