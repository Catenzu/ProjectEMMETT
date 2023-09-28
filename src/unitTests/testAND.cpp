/*
** EPITECH PROJECT, 2023
** testAND.cpp$
** File description:
** testAND.cpp$
*/

#include "../../include/emmett.h"

void test_AND(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    //immediate
    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0x29;
    cpu.memory[0x1001]._value = 0b00001111;
    cpu.reset();
    cpu.a._value = 0b00110011;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: AND Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu.a._value != 0b00000011) {
        std::cerr << "FAILURE: AND Immediate: " << (int) cpu.a._value << " != 0x0A" << std::endl;
    } else
        std::cout << "SUCCESS: AND Immediate: " << (int) cpu.a._value << std::endl;
    cpu.clear();

    //zero page
}