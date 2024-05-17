/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::JMP_ABS(int &cycles)
{
    unsigned char low = fetch(cycles); //1cycle
    unsigned char high = fetch(cycles); //1cycle

    uint16_t address = ((uint16_t)high * 256) + (uint16_t)low;
    _pc = address;
    if (_debugPrint)
        std::cout << "--JMP Absolute: " << (int) _pc << std::endl;
}

void MOS6502::JMP_IND(int &cycles)
{
    unsigned char low = fetch(cycles); //1cycle
    unsigned char high = fetch(cycles); //1cycle

    uint16_t address = ((uint16_t)high * 256) + (uint16_t)low;
    uint16_t newLow = getMemory(address, cycles); //1cycle
    low += 1; //Important: if low is 255, it will overflow to 0, it's a common bug for 6502
    address = ((uint16_t)high * 256) + (uint16_t)low;
    uint16_t newHigh = getMemory(address, cycles); //1cycle
    uint16_t newAddress = ((uint16_t)newHigh * 256) + (uint16_t)newLow;
    _pc = newAddress;
    if (_debugPrint)
        std::cout << "--JMP Indirect: " << (int) _pc << std::endl;
}

void MOS6502::JSR_ABS(int &cycles)
{
    unsigned char low = fetch(cycles); //1cycle
    unsigned char high = fetch(cycles); //1cycle

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

    _pc = address;
    cycles--; //1cycle
    if (_debugPrint)
        std::cout << "--JSR Absolute: " << (int) _pc << std::endl;
}

void MOS6502::RTS(int &cycles)
{
    _sp._value++;
    unsigned char pcLow = getMemory(0x0100 + _sp._value,cycles); //1cycle
    cycles--; //1cycle

    _sp._value++;
    unsigned char pcHigh = getMemory(0x0100 + _sp._value,cycles); //1cycle
    cycles--; //1cycle

    uint16_t pc = ((uint16_t)pcHigh * 256) + (uint16_t)pcLow;
    cycles--; //1cycle
    _pc = pc + 1;

    if (_debugPrint)
        std::cout << "--RTS: " << (int) _pc << std::endl;
}
