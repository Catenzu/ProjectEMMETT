/*
** EPITECH PROJECT, 2023
** testAND.cpp$
** File description:
** testAND.cpp$
*/

#include "../../include/emmett.h"

void test_ORA(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    //immediate
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x09;
    cpu._memory[0x1001]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ORA Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111111) {
        std::cerr << "FAILURE: ORA Immediate: " << (int) cpu._a._value << " != 0b00111111" << std::endl;
    } else
        std::cout << "SUCCESS: ORA Immediate: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //zero page

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x05;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;

    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: ORA Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111111) {
        std::cerr << "FAILURE: ORA Zero Page: " << (int) cpu._a._value << " != 0b00111111" << std::endl;
    } else
        std::cout << "SUCCESS: ORA Zero Page: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //zero page x

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x15;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._x._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ORA Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111111) {
        std::cerr << "FAILURE: ORA Zero Page X: " << (int) cpu._a._value << " != 0b00111111" << std::endl;
    } else {
        std::cout << "SUCCESS: ORA Zero Page X: " << (int) cpu._a._value << std::endl;
    }
    cpu.clear();

    //absolute

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x0D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ORA Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111111) {
        std::cerr << "FAILURE: ORA Absolute: " << (int) cpu._a._value << " != 0b00111111" << std::endl;
    } else
        std::cout << "SUCCESS: ORA Absolute: " << (int) cpu._a._value << std::endl;
    cpu.clear();


    //absolute x

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x1D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._x._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ORA Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111111) {
        std::cerr << "FAILURE: ORA Absolute X: " << (int) cpu._a._value << " != 0b00111111" << std::endl;
    } else
        std::cout << "SUCCESS: ORA Absolute X: " << (int) cpu._a._value << std::endl;
    cpu.clear();


    //absolute y

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x19;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._y._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: ORA Absolute Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111111) {
        std::cerr << "FAILURE: ORA Absolute Y: " << (int) cpu._a._value << " != 0b00111111" << std::endl;
    } else
        std::cout << "SUCCESS: ORA Absolute Y: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //indirect x

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x01;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0007]._value = 0x0B;
    cpu._memory[0x0008]._value = 0x00;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._x._value = 0x02;

    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: ORA Indirect X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111111) {
        std::cerr << "FAILURE: ORA Indirect X: " << (int) cpu._a._value << " != 0b00111111" << std::endl;
    } else
        std::cout << "SUCCESS: ORA Indirect X: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //indirect y

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x11;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x0B;
    cpu._memory[0x0006]._value = 0x00;
    cpu._memory[0x000D]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._y._value = 0x02;

    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: ORA Indirect Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111111) {
        std::cerr << "FAILURE: ORA Indirect Y: " << (int) cpu._a._value << " != 0b00111111" << std::endl;
    } else
        std::cout << "SUCCESS: ORA Indirect Y: " << (int) cpu._a._value << std::endl;
    cpu.clear();
}