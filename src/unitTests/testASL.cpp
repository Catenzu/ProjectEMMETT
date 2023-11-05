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
    cpu.clear();
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

    // ASL ACC with carry
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0x01;
    cpu.setCarryFlag(true);
    if ((cycleUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ASL ACC with carry cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x02) {
        std::cerr << "FAILURE: ASL ACC with carry: " << (int) cpu._a._value << " != 0x02" << std::endl;
    } else
        std::cout << "SUCCESS: ASL ACC with carry: " << (int) cpu._a._value << std::endl;

    // ASL ACC no carry
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0b11110001;
    if ((cycleUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ASL ACC no carry cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11100010) {
        std::cerr << "FAILURE: ASL ACC no carry: " << std::bitset<8>(cpu._a._value) << " != 0b11100010" << std::endl;
    } else
        std::cout << "SUCCESS: ASL ACC no carry: " << (int) cpu._a._value << std::endl;
    if (cpu._sr._value != 0b10000001)
        std::cerr << "FAILURE: ASL ACC no carry: flags not correct" << std::endl;
    else
        std::cout << "SUCCESS: ASL ACC no carry: flags correct" << std::endl;

    // ASL Zero Page
    cpu.clear();
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

    // ASL Zero Page X
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x16;
    cpu._memory[0x1001]._value = 0x09;
    cpu._memory[0x000A]._value = 0x01;
    cpu.reset();
    cpu._x._value = 0x01;
    if ((cycleUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: ASL Zero Page X cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x02) {
        std::cerr << "FAILURE: ASL Zero Page X: " << (int) cpu._memory[0x000A]._value << " != 0x02" << std::endl;
    } else
        std::cout << "SUCCESS: ASL Zero Page X: " << (int) cpu._memory[0x000A]._value << std::endl;

    // ASL Absolute
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x0E;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0x01;
    cpu.reset();
    if ((cycleUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: ASL Absolute cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x02) {
        std::cerr << "FAILURE: ASL Absolute: " << (int) cpu._memory[0x000A]._value << " != 0x02" << std::endl;
    } else
        std::cout << "SUCCESS: ASL Absolute: " << (int) cpu._memory[0x000A]._value << std::endl;

    // ASL Absolute X
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x1E;
    cpu._memory[0x1001]._value = 0x09;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0x01;
    cpu.reset();
    cpu._x._value = 0x01;
    if ((cycleUsed = cpu.execute(7)) != 0)
        std::cerr << "FAILURE: ASL Absolute X cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x02) {
        std::cerr << "FAILURE: ASL Absolute X: " << (int) cpu._memory[0x000A]._value << " != 0x02" << std::endl;
    } else
        std::cout << "SUCCESS: ASL Absolute X: " << (int) cpu._memory[0x000A]._value << std::endl;
    return 0;
}