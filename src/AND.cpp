/*
** EPITECH PROJECT, 2023
** AND.cpp$
** File description:
** AND.cpp$
*/

#include "../include/emmett.h"

void MOS6502::AND_IM(int &cycles)
{
    unsigned char value = fetch(cycles);
    unsigned char result = a._value & value;

    setNegativeFlag(result);
    setZeroFlag(result);
    a.set(result);
    std::cout << "AND: " << (int) a._value << std::endl;
}