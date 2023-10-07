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

    // ADC Immediate

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

    // ADC Zero Page

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

    // ADC Zero Page, X

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x75;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0x10;
    cpu._x._value = 0x55;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ADC Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: ADC Zero Page X: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Zero Page X: " << (int) cpu._a._value << std::endl;
    cpu.clear();
    cpu._x._value = 0x00;

    // ADC Absolute

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x6D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x0B;
    cpu._memory[0x0B0A]._value = 0x10;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ADC Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: ADC Absolute: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Absolute: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //ADC Absolute X

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x7D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x0B;
    cpu._memory[0x0B0A]._value = 0x10;
    cpu._x._value = 0x55;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ADC Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: ADC Absolute X: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Absolute X: " << (int) cpu._a._value << std::endl;
    cpu.clear();
    cpu._x._value = 0x00;

    //ADC Absolute Y

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x79;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x0B;
    cpu._memory[0x0B0A]._value = 0x10;
    cpu._y._value = 0x55;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ADC Absolute Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: ADC Absolute Y: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Absolute Y: " << (int) cpu._a._value << std::endl;
    cpu.clear();
    cpu._y._value = 0x00;

    //ADC Indirect X

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x0010]._value = 0x61;
    cpu._memory[0x0011]._value = 0x0A;
    cpu._memory[0x0A0A]._value = 0x0B;
    cpu._memory[0x0A0B]._value = 0x0C;
    cpu._memory[0x0C0B]._value = 0x10;
    cpu.reset();
    cpu._a._value = 0x05;
    cpu._x._value = 0x05;
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: ADC Indirect X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x15) {
        std::cerr << "FAILURE: ADC Indirect X: " << (int) cpu._a._value << " != 0x15" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Indirect X: " << (int) cpu._a._value << std::endl;
    cpu.clear();
    cpu._x._value = 0x00;

    //ADC Indirect Y

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x0010]._value = 0x71;
    cpu._memory[0x0011]._value = 0x0A;
    cpu._memory[0x0A0A]._value = 0x0B;
    cpu._memory[0x0A0B]._value = 0x0C;
    cpu._memory[0x0C0B]._value = 0x10;
    cpu.reset();
    cpu._a._value = 0x05;
    cpu._y._value = 0x05;
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: ADC Indirect Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x15) {
        std::cerr << "FAILURE: ADC Indirect Y: " << (int) cpu._a._value << " != 0x15" << std::endl;
    } else
        std::cout << "SUCCESS: ADC Indirect Y: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    return (0);
}
