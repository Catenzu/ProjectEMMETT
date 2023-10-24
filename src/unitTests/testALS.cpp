/*
** EPITECH PROJECT, 2023
** testALS.cpp$
** File description:
** testALS.cpp$
*/

#include "../../include/emmett.h"

int test_ASL(MOS6502 &cpu)
{
    int cycleUsed = 0;

    // ASL ACC

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0x01;
    if ((cycleUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ASL ACC cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x02) {
        std::cerr << "FAILURE: ASL ACC: " << (int) cpu._a._value << " != 0x02" << std::endl;
    } else
        std::cout << "SUCCESS: ASL ACC: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    // ASL Zero Page

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x06;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0x01;
    cpu.reset();
    if ((cycleUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: ASL Zero Page cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x02) {
        std::cerr << "FAILURE: ASL Zero Page: " << (int) cpu._memory[0x000A]._value << " != 0x02" << std::endl;
    } else
        std::cout << "SUCCESS: ASL Zero Page: " << (int) cpu._memory[0x000A]._value << std::endl;
    cpu.clear();
    return 0;
}