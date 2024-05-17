/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::NOP(int &cycles)
{
    cycles--;
    if (_debugPrint)
        std::cout << "--NOP" << std::endl;
}