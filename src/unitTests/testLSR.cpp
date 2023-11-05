/*
** EPITECH PROJECT, 2023
** testALS.cpp$
** File description:
** testALS.cpp$
*/

#include "../../include/emmett.h"

int test_LSR(MOS6502 &cpu)
{
    int cycleUsed = 0;

    // LSR ACC
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x4A;
    cpu.reset();

    cpu._a._value = 0x02;
    if ((cycleUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LSR ACC cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x01) {
        std::cerr << "FAILURE: LSR ACC: " << (int) cpu._a._value << " != 0x01" << std::endl;
    } else
        std::cout << "SUCCESS: LSR ACC: " << (int) cpu._a._value << std::endl;

    // LSR ACC with carry
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x4A;

    cpu.reset();
    cpu._a._value = 0x02;
    cpu.setCarryFlag(true);
    if ((cycleUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LSR ACC with carry cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x01) {
        std::cerr << "FAILURE: LSR ACC with carry: " << (int) cpu._a._value << " != 0x01" << std::endl;
    } else
        std::cout << "SUCCESS: LSR ACC with carry: " << (int) cpu._a._value << std::endl;

    // LSR ACC no carry
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x4A;
    cpu.reset();
    cpu._a._value = 0b11110001;

    if ((cycleUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LSR ACC no carry cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b01111000) {
        std::cerr << "FAILURE: LSR ACC no carry: " << std::bitset<8>(cpu._a._value) << " != 0b01111000" << std::endl;
    } else
        std::cout << "SUCCESS: LSR ACC no carry: " << (int) cpu._a._value << std::endl;
    if (cpu._sr._value != 0b00000001)
        std::cerr << "FAILURE: LSR ACC no carry: flags not correct" << std::endl;
    else
        std::cout << "SUCCESS: LSR ACC no carry: flags correct" << std::endl;

    // LSR Zero Page
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x46;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0x02;
    cpu.reset();

    if ((cycleUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: LSR Zero Page cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x01) {
        std::cerr << "FAILURE: LSR Zero Page: " << (int) cpu._memory[0x000A]._value << " != 0x01" << std::endl;
    } else
        std::cout << "SUCCESS: LSR Zero Page: " << (int) cpu._memory[0x000A]._value << std::endl;

    // LSR Zero Page X
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x56;
    cpu._memory[0x1001]._value = 0x09;
    cpu._memory[0x000A]._value = 0x02;
    cpu.reset();
    cpu._x._value = 0x01;

    if ((cycleUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: LSR Zero Page X cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x01) {
        std::cerr << "FAILURE: LSR Zero Page X: " << (int) cpu._memory[0x000A]._value << " != 0x01" << std::endl;
    } else
        std::cout << "SUCCESS: LSR Zero Page X: " << (int) cpu._memory[0x000A]._value << std::endl;

    // LSR Absolute
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x4E;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x0A;
    cpu._memory[0x0A0A]._value = 0x02;
    cpu.reset();

    if ((cycleUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: LSR Absolute cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._memory[0x0A0A]._value != 0x01) {
        std::cerr << "FAILURE: LSR Absolute: " << (int) cpu._memory[0x0A0A]._value << " != 0x01" << std::endl;
    } else
        std::cout << "SUCCESS: LSR Absolute: " << (int) cpu._memory[0x0A0A]._value << std::endl;

    // LSR Absolute X
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x5E;
    cpu._memory[0x1001]._value = 0x09;
    cpu._memory[0x1002]._value = 0x0A;
    cpu._memory[0x0A0A]._value = 0x02;
    cpu.reset();

    cpu._x._value = 0x01;
    if ((cycleUsed = cpu.execute(7)) != 0)
        std::cerr << "FAILURE: LSR Absolute X cycles Used: " << cycleUsed << " != 0" << std::endl;
    if (cpu._memory[0x0A0A]._value != 0x01) {
        std::cerr << "FAILURE: LSR Absolute X: " << (int) cpu._memory[0x0A0A]._value << " != 0x01" << std::endl;
    } else
        std::cout << "SUCCESS: LSR Absolute X: " << (int) cpu._memory[0x0A0A]._value << std::endl;
    return 0;
}