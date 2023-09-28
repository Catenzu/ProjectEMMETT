/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::LDY_IM(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle

    _y.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDY Immediate: " << (int) _y._value << std::endl;
}

void MOS6502::LDY_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char value = getMemory(address, cycles); //1cycle

    _y.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDY Zero Page: " << (int) _y._value << std::endl;
}

void MOS6502::LDY_ZEROX(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    address = aluAddition(address, xV, cycles); //1cycle
    unsigned char value = getMemory(address, cycles); //1cycle

    _y.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDY ZeroY Page: " << (int) _y._value << std::endl;
}

void MOS6502::LDY_ABS(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char adress2 = fetch(cycles); //1cycle
    uint16_t address = ((uint16_t)adress2 * 256) + (uint16_t)address1;
    unsigned char value = getMemory(address, cycles); //1cycle

    _y.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDY Absolute: " << (int) _y._value << std::endl;
}

void MOS6502::LDY_ABSX(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    unsigned char address = aluAddition(address1, xV, cycles); //1cycle
    cycles++; //done during the fetching of address2

    unsigned char address2 = fetch(cycles); //1cycle
    uint16_t completeAddress = (uint16_t) address + ((uint16_t)address2 * 256);
    if (_aluAdditionCarry) {//if the sum of address1 and X has a carry,
        cycles--;       // we need to add the carry to the second byte of the address, taking one cycle (HW Simulation)
        completeAddress += 0x0100;
    }
    unsigned char value = getMemory(completeAddress, cycles); //1cycle

    _y.set(value);
    setNegativeFlag(value);
    setZeroFlag(value);
    std::cout << "--LDY Absolute X: " << (int) _y._value << std::endl;
}