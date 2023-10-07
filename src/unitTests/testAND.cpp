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
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x29;
    cpu._memory[0x1001]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: AND Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00000011) {
        std::cerr << "FAILURE: AND Immediate: " << (int) cpu._a._value << " != 0x0A" << std::endl;
    } else
        std::cout << "SUCCESS: AND Immediate: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //zero page

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x25;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;

    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: AND Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00000011) {
        std::cerr << "FAILURE: AND Zero Page: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: AND Zero Page: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //zero page x

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x35;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._x._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: AND Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00000011) {
        std::cerr << "FAILURE: AND Zero Page X: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: AND Zero Page X: " << (int) cpu._a._value << std::endl;
    }
    cpu.clear();

    //absolute

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: AND Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00000011) {
        std::cerr << "FAILURE: AND Absolute: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: AND Absolute: " << (int) cpu._a._value << std::endl;
    cpu.clear();


    //absolute x

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x3D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._x._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: AND Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00000011) {
        std::cerr << "FAILURE: AND Absolute X: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: AND Absolute X: " << (int) cpu._a._value << std::endl;
    cpu.clear();


    //absolute y

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x39;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._y._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: AND Absolute Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00000011) {
        std::cerr << "FAILURE: AND Absolute Y: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: AND Absolute Y: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //indirect x

    //indirect y

}