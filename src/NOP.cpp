/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::NOP(int &cycles)
{
    cycles--;
    std::cout << "--NOP" << std::endl;
}