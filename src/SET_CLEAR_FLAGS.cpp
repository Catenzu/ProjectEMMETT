/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::CLC(int &cycles) //clear carry flag
{
    _sr.set(_sr._value & 0b11111110);
    cycles--;
    if (_debugPrint)
        std::cout << "--CLC" << std::endl;
}

void MOS6502::CLD(int &cycles) //clear decimal flag
{
    _sr.set(_sr._value & 0b11110111);
    cycles--;
    if (_debugPrint)
        std::cout << "--CLD" << std::endl;
}

void MOS6502::CLI(int &cycles) //clear interrupt flag
{
    _sr.set(_sr._value & 0b11111011);
    cycles--;
    if (_debugPrint)
        std::cout << "--CLI" << std::endl;
}

void MOS6502::CLV(int &cycles) //clear overflow flag
{
    _sr.set(_sr._value & 0b10111111);
    cycles--;
    if (_debugPrint)
        std::cout << "--CLV" << std::endl;
}

void MOS6502::SEC(int &cycles) //set carry flag
{
    _sr.set(_sr._value | 0b00000001);
    cycles--;
    if (_debugPrint)
        std::cout << "--SEC" << std::endl;
}

void MOS6502::SED(int &cycles) //set decimal flag
{
    _sr.set(_sr._value | 0b00001000);
    cycles--;
    if (_debugPrint)
        std::cout << "--SED" << std::endl;
}

void MOS6502::SEI(int &cycles) //set interrupt flag
{
    _sr.set(_sr._value | 0b00000100);
    cycles--;
    if (_debugPrint)
        std::cout << "--SEI" << std::endl;
}