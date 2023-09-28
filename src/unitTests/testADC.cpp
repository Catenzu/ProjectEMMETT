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

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x69;
    cpu._memory[0x1001]._value = 0x0A;
    cpu.reset();

    if (cpu.execute(2) != 0)
        std::cerr << "FAILURE: ADC Immediate cycles Used: " << cpu.execute(2) << " != 0" << std::endl;
    if (cpu._a._value != 0x0A) {
        std::cerr << "FAILURE: ADC Immediate: " << (int) cpu._a._value << " != 0x0A" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Immediate: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x65;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0x10;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: ADC Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: ADC Zero Page: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Zero Page: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0x75;
    cpu.memory[0x1001]._value = 0x0A;
    cpu.memory[0x000A]._value = 0x10;
    cpu.x._value = 0x55;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ADC Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu.a._value != 0x10) {
        std::cerr << "FAILURE: ADC Zero Page X: " << (int) cpu.a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Zero Page X: " << (int) cpu.a._value << std::endl;
    cpu.clear();
    cpu.x._value = 0x00;

    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0x6D;
    cpu.memory[0x1001]._value = 0x0A;
    cpu.memory[0x1002]._value = 0x0B;
    cpu.memory[0x0B0A]._value = 0x10;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ADC Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu.a._value != 0x10) {
        std::cerr << "FAILURE: ADC Absolute: " << (int) cpu.a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Absolute: " << (int) cpu.a._value << std::endl;
    cpu.clear();

    return (0);
}
