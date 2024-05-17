/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::STA_ZERO(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    setMemory(address, _a._value,cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STA Zero Page: " << (int) _a._value << std::endl;
}

void MOS6502::STA_ZEROX(int &cycles)
{
    unsigned char address = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    address = aluAddition(address, xV, cycles); //1cycle
    setMemory(address, _a._value,cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STA ZeroX Page: " << (int) _a._value << std::endl;
}

void MOS6502::STA_ABS(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char adress2 = fetch(cycles); //1cycle
    uint16_t address = ((uint16_t)adress2 * 256) + (uint16_t)address1;
    setMemory(address, _a._value, cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STA Absolute: " << (int) _a._value << std::endl;
}

void MOS6502::STA_ABSX(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    unsigned char address = aluAddition(address1, xV, cycles); //1cycle

    unsigned char address2 = fetch(cycles); //1cycle
    uint16_t completeAddress = (uint16_t) address + ((uint16_t)address2 * 256);
    if (_aluAdditionCarry) //if the sum of address1 and X has _a carry,
        completeAddress += 0x0100;
    setMemory(completeAddress, _a._value,cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STA Absolute X: " << (int) _a._value << std::endl;
}

void MOS6502::STA_ABSY(int &cycles)
{
    unsigned char address1 = fetch(cycles); //1cycle
    unsigned char yV = _y._value;
    unsigned char address = aluAddition(address1, yV, cycles); //1cycle

    unsigned char address2 = fetch(cycles); //1cycle
    uint16_t completeAddress = (uint16_t) address + ((uint16_t)address2 * 256);
    if (_aluAdditionCarry) //if the sum of address1 and X has _a carry,
        completeAddress += 0x0100;
    setMemory(completeAddress, _a._value,cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STA Absolute Y: " << (int) _a._value << std::endl;
}

void MOS6502::STA_INDX(int &cycles)
{
    unsigned char zeroPageAddress = fetch(cycles); //1cycle
    unsigned char xV = _x._value;
    zeroPageAddress += xV;
    cycles--; //1cycle
    unsigned char address1 = getMemory(zeroPageAddress, cycles); //1cycle
    unsigned char address2 = getMemory(zeroPageAddress + 1, cycles); //1cycle
    uint16_t address = ((uint16_t)address2 * 256) + (uint16_t)address1;

    setMemory(address, _a._value, cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STA Indirect X: " << (int) _a._value << std::endl;
}

void MOS6502::STA_INDY(int &cycles)
{
    unsigned char zeroPageAddress = fetch(cycles); //1cycle
    unsigned char address1 = getMemory(zeroPageAddress, cycles); //1cycle
    unsigned char yV = _y._value;
    unsigned char address = aluAddition(address1, yV, cycles); //1cycle

    unsigned char address2 = getMemory(zeroPageAddress + 1, cycles); //1cycle
    uint16_t completeAddress = (uint16_t) address + ((uint16_t)address2 * 256);

    if (_aluAdditionCarry)
        completeAddress += 0x0100;
    setMemory(completeAddress, _a._value, cycles); //1cycle

    if (_debugPrint)
        std::cout << "--STA Indirect Y: " << (int) _a._value << std::endl;
}
