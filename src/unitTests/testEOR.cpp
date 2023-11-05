/*
** EPITECH PROJECT, 2023
** testAND.cpp$
** File description:
** testAND.cpp$
*/

#include "../../include/emmett.h"

void test_EOR(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    //immediate
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x49;
    cpu._memory[0x1001]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: EOR Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111100) {
        std::cerr << "FAILURE: EOR Immediate: " << (int) cpu._a._value << " != 0b00111100" << std::endl;
    } else
        std::cout << "SUCCESS: EOR Immediate: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //zero page

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x45;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;

    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: EOR Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111100) {
        std::cerr << "FAILURE: EOR Zero Page: " << (int) cpu._a._value << " != 0b00111100" << std::endl;
    } else
        std::cout << "SUCCESS: EOR Zero Page: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //zero page x

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x55;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._x._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: EOR Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111100) {
        std::cerr << "FAILURE: EOR Zero Page X: " << (int) cpu._a._value << " != 0b00111100" << std::endl;
    } else {
        std::cout << "SUCCESS: EOR Zero Page X: " << (int) cpu._a._value << std::endl;
    }
    cpu.clear();

    //absolute

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x4D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: EOR Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111100) {
        std::cerr << "FAILURE: EOR Absolute: " << (int) cpu._a._value << " != 0b00111100" << std::endl;
    } else
        std::cout << "SUCCESS: EOR Absolute: " << (int) cpu._a._value << std::endl;
    cpu.clear();


    //absolute x

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x5D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._x._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: EOR Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111100) {
        std::cerr << "FAILURE: EOR Absolute X: " << (int) cpu._a._value << " != 0b00111100" << std::endl;
    } else
        std::cout << "SUCCESS: EOR Absolute X: " << (int) cpu._a._value << std::endl;
    cpu.clear();


    //absolute y

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x59;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x00;
    cpu._memory[0x000A]._value = 0b00001111;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._y._value = 0x01;

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: EOR Absolute Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111100) {
        std::cerr << "FAILURE: EOR Absolute Y: " << (int) cpu._a._value << " != 0b00111100" << std::endl;
    } else
        std::cout << "SUCCESS: EOR Absolute Y: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //indirect x

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x41;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0007]._value = 0x0B;
    cpu._memory[0x0008]._value = 0x00;
    cpu._memory[0x000B]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._x._value = 0x02;

    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: EOR Indirect X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111100) {
        std::cerr << "FAILURE: EOR Indirect X: " << (int) cpu._a._value << " != 0b00111100" << std::endl;
    } else
        std::cout << "SUCCESS: EOR Indirect X: " << (int) cpu._a._value << std::endl;
    cpu.clear();

    //indirect y

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x51;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x0B;
    cpu._memory[0x0006]._value = 0x00;
    cpu._memory[0x000D]._value = 0b00001111;
    cpu.reset();
    cpu._a._value = 0b00110011;
    cpu._y._value = 0x02;

    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: EOR Indirect Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b00111100) {
        std::cerr << "FAILURE: EOR Indirect Y: " << (int) cpu._a._value << " != 0b00111100" << std::endl;
    } else
        std::cout << "SUCCESS: EOR Indirect Y: " << (int) cpu._a._value << std::endl;
    cpu.clear();
}