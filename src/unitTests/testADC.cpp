/*
** EPITECH PROJECT, 2023
** testADC.cpp$
** File description:
** testADC.cpp$
*/

#include "../../include/emmett.h"

int test_ADC(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0x69;
    cpu.memory[0x1001]._value = 0x0A;
    cpu.reset();

    if (cpu.execute(2) != 0)
        std::cerr << "FAILURE: ADC Immediate cycles Used: " << cpu.execute(2) << " != 0" << std::endl;
    if (cpu.a._value != 0x0A) {
        std::cerr << "FAILURE: ADC Immediate: " << (int) cpu.a._value << " != 0x0A" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Immediate: " << (int) cpu.a._value << std::endl;
    cpu.clear();

    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0x65;
    cpu.memory[0x1001]._value = 0x0A;
    cpu.memory[0x000A]._value = 0x10;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: ADC Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu.a._value != 0x10) {
        std::cerr << "FAILURE: ADC Zero Page: " << (int) cpu.a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Zero Page: " << (int) cpu.a._value << std::endl;
    cpu.clear();

    return (0);
}
