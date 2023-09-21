/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::LDA_IM(int &cycles)
{
    unsigned char value = fetch(cycles);

    a.set(value);
    if (value == 0)
        sr._value = sr._value | 0b00000010; //set the 7th bit to 1
    if (value & 0b10000000) //if the 7th bit is 1
        sr._value = sr._value | 0b10000000; //set the 0th bit to 1
    std::cout << "LDA: " << (int) a._value << std::endl;
}