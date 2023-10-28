/*
 * Emmett
 */

#include "../include/emmett.h"

uint16_t MOS6502::getAdressZeroPage(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle

    return (uint16_t)address;
}

uint16_t MOS6502::getAdressZeroPageX(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    address = aluAddition(address, xV, cycles); //1cycle

    return (uint16_t)address;
}

uint16_t MOS6502::getAdressZeroPageY(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char yV = _y._value;
    address = aluAddition(address, yV, cycles); //1cycle

    return (uint16_t)address;
}

uint16_t MOS6502::getAdressAbsolute(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char adress2 = fetch(cycles); //1cycle
    uint16_t address = ((uint16_t)adress2 * 256) + (uint16_t)address1;

    return address;
}

uint16_t MOS6502::getAdressAbsoluteX(int &cycles)
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

    return completeAddress;
}

uint16_t MOS6502::getAdressAbsoluteY(int &cycles)
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

    return completeAddress;
}

uint16_t MOS6502::getAdressIndirectX(int &cycles)
{
    unsigned char zeroPageAddress = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    zeroPageAddress += xV;
    cycles--; //1cycle
    unsigned char address1 = getMemory(zeroPageAddress, cycles); //1cycle
    unsigned char address2 = getMemory(zeroPageAddress + 1, cycles); //1cycle
    uint16_t address = ((uint16_t)address2 * 256) + (uint16_t)address1;

    return address;
}

uint16_t MOS6502::getAdressIndirectY(int &cycles)
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

    return completeAddress;
}