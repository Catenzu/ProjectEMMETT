/*
 * Emmett
 */

#include "../include/emmett.h"

unsigned char MOS6502::getValueImmediate(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle

    return value;
}

unsigned char MOS6502::getValueZeroPage(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char value = getMemory(address, cycles); //1cycle

    return value;
}

unsigned char MOS6502::getValueZeroPageX(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    address = aluAddition(address, xV, cycles); //1cycle
    unsigned char value = getMemory(address, cycles); //1cycle

    return value;
}

unsigned char MOS6502::getValueZeroPageY(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char yV = _y._value;
    address = aluAddition(address, yV, cycles); //1cycle
    unsigned char value = getMemory(address, cycles); //1cycle

    return value;
}

unsigned char MOS6502::getValueAbsolute(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char adress2 = fetch(cycles); //1cycle
    uint16_t address = ((uint16_t)adress2 * 256) + (uint16_t)address1;
    unsigned char value = getMemory(address, cycles); //1cycle

    return value;
}

unsigned char MOS6502::getValueAbsoluteX(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    unsigned char address = aluAddition(address1, xV, cycles); //1cycle
    cycles++; //done during the fetching of address2

    unsigned char address2 = fetch(cycles); //1cycle
    uint16_t completeAddress = (uint16_t) address + ((uint16_t)address2 * 256);
    if (_aluAdditionCarry) {//if the sum of address1 and X has _a carry,
        cycles--;       // we need to add the carry to the second byte of the address, taking one cycle (HW Simulation)
        completeAddress += 0x0100;
    }
    unsigned char value = getMemory(completeAddress, cycles); //1cycle

    return value;
}

unsigned char MOS6502::getValueAbsoluteY(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char yV = _y._value;
    unsigned char address = aluAddition(address1, yV, cycles); //1cycle
    cycles++; //done during the fetching of address2

    unsigned char address2 = fetch(cycles); //1cycle
    uint16_t completeAddress = (uint16_t) address + ((uint16_t)address2 * 256);
    if (_aluAdditionCarry) {//if the sum of address1 and X has a carry,
        cycles--;       // we need to add the carry to the second byte of the address, taking one cycle (HW Simulation)
        completeAddress += 0x0100;
    }
    unsigned char value = getMemory(completeAddress, cycles); //1cycle

    return value;
}

unsigned char MOS6502::getValueIndirectX(int &cycles)
{
    unsigned char zeroPageAddress = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    zeroPageAddress += xV;
    cycles--; //1cycle
    unsigned char address1 = getMemory(zeroPageAddress, cycles); //1cycle
    unsigned char address2 = getMemory(zeroPageAddress + 1, cycles); //1cycle
    uint16_t address = ((uint16_t)address2 * 256) + (uint16_t)address1;

    unsigned char value = getMemory(address, cycles); //1cycle

    return value;
}

unsigned char MOS6502::getValueIndirectY(int &cycles)
{
    unsigned char zeroPageAddress = fetch(cycles); //1cycle
    unsigned char address1 = getMemory(zeroPageAddress, cycles); //1cycle
    unsigned char yV = _y._value;
    unsigned char address = aluAddition(address1, yV, cycles); //1cycle
    cycles++; //done during the fetching of address2

    unsigned char address2 = getMemory(zeroPageAddress + 1, cycles); //1cycle
    uint16_t completeAddress = (uint16_t) address + ((uint16_t)address2 * 256);

    if (_aluAdditionCarry) {//if the sum of address1 and X has _a carry,
        cycles--;       // we need to add the carry to the second byte of the address, taking one cycle (HW Simulation)
        completeAddress += 0x0100;
    }
    unsigned char value = getMemory(completeAddress, cycles); //1cycle

    return value;
}