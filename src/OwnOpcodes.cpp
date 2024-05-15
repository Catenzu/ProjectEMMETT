/*
** EPITECH PROJECT, 2023
** ADC.cpp$
** File description:
** ADC.cpp$
*/

#include "../include/emmett.h"

void MOS6502::END(int &cycles)
{
    _return = true;
    if (_debugPrint)
        std::cout << "--END" << std::endl;
}

void MOS6502::PRT_IM(int &cycles)
{
    unsigned char value = getValueImmediate(cycles);

    char tmp[2] = {static_cast<char>(value), '\0'};
    std::cout << std::string(tmp);
}

void MOS6502::PRT_ZERO(int &cycles)
{
    unsigned char value = getValueZeroPage(cycles);

    char tmp[2] = {static_cast<char>(value), '\0'};
    std::cout << std::string(tmp);
}

void MOS6502::PRT_ZEROX(int &cycles)
{
    unsigned char value = getValueZeroPageX(cycles);

    char tmp[2] = {static_cast<char>(value), '\0'};
    std::cout << std::string(tmp);
}

void MOS6502::PRT_ABS(int &cycles)
{
    unsigned char value = getValueAbsolute(cycles);

    char tmp[2] = {static_cast<char>(value), '\0'};
    std::cout << std::string(tmp);
}

void MOS6502::PRT_ABSX(int &cycles)
{
    unsigned char value = getValueAbsoluteX(cycles);

    char tmp[2] = {static_cast<char>(value), '\0'};
    std::cout << std::string(tmp);
}

void MOS6502::PRT_ABSY(int &cycles)
{
    unsigned char value = getValueAbsoluteY(cycles);

    char tmp[2] = {static_cast<char>(value), '\0'};
    std::cout << std::string(tmp);
}

void MOS6502::PRT_INDX(int &cycles)
{
    unsigned char value = getValueIndirectX(cycles);

    char tmp[2] = {static_cast<char>(value), '\0'};
    std::cout << std::string(tmp);
}

void MOS6502::PRT_INDY(int &cycles)
{
    unsigned char value = getValueIndirectY(cycles);

    char tmp[2] = {static_cast<char>(value), '\0'};
    std::cout << std::string(tmp);
}