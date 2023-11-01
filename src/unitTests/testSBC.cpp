/*
** EPITECH PROJECT, 2023
** testADC.cpp$
** File description:
** testADC.cpp$
*/

#include <bitset>
#include "../../include/emmett.h"

int test_SBC(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // SBC Immediate 0 - 0
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE9;
    cpu._memory[0x1001]._value = 0x00;
    cpu.reset();

    cpu.setCarryFlag(true);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: SBC Immediate cycles Used (0 - 0): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x00) {
        std::cerr << "FAILURE: SBC Immediate (0 - 0): " << (int) cpu._a._value << " != 0x00" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Immediate (0 - 0): " << (int) cpu._a._value << std::endl;

    // SBC Immediate 0 - 0 - 1
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE9;
    cpu._memory[0x1001]._value = 0x00;
    cpu.reset();

    cpu.setCarryFlag(false);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: SBC Immediate cycles Used (0 - 0 - 1): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0xFF) {
        std::cerr << "FAILURE: SBC Immediate (0 - 0 - 1): " << (int) cpu._a._value << " != 0xFF" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Immediate (0 - 0 - 1): " << (int) cpu._a._value << std::endl;

    // SBC Immediate 0 - 10
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE9;
    cpu._memory[0x1001]._value = 0b00001010;
    cpu.reset();

    cpu.setCarryFlag(true);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: SBC Immediate cycles Used (0 - 10): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC Immediate (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Immediate (0 - 10): " << (int) cpu._a._value << std::endl;

    // SBC ZeroPage 0 - 10
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE5;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x0010]._value = 0b00001010;
    cpu.reset();

    cpu.setCarryFlag(true);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: SBC ZeroPage cycles Used (0 - 10): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC ZeroPage (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC ZeroPage (0 - 10): " << (int) cpu._a._value << std::endl;

    // SBC ZeroPage X 0 - 10
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xF5;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x001A]._value = 0b00001010;
    cpu.reset();

    cpu._x.set(0x0A);
    cpu.setCarryFlag(true);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: SBC ZeroPage X cycles Used (0 - 10): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC ZeroPage X (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC ZeroPage X (0 - 10): " << (int) cpu._a._value << std::endl;

    // SBC Absolute 0 - 10
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xED;
    cpu._memory[0x1001]._value = 0xAA;
    cpu._memory[0x1002]._value = 0x30;
    cpu._memory[0x30AA]._value = 0b00001010;
    cpu.reset();

    cpu.setCarryFlag(true);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: SBC Absolute cycles Used (0 - 10): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC Absolute (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Absolute (0 - 10): " << (int) cpu._a._value << std::endl;

    // SBC Absolute X 0 - 10
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xFD;
    cpu._memory[0x1001]._value = 0xA0;
    cpu._memory[0x1002]._value = 0x30;
    cpu._memory[0x30AA]._value = 0b00001010;
    cpu.reset();

    cpu.setCarryFlag(true);
    cpu._x.set(0x0A);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: SBC Absolute X cycles Used (0 - 10): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC Absolute X (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Absolute X (0 - 10): " << (int) cpu._a._value << std::endl;


    // SBC Absolute Y 0 - 10
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xF9;
    cpu._memory[0x1001]._value = 0xA0;
    cpu._memory[0x1002]._value = 0x30;
    cpu._memory[0x30AA]._value = 0b00001010;
    cpu.reset();

    cpu.setCarryFlag(true);
    cpu._y.set(0x0A);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: SBC Absolute Y cycles Used (0 - 10): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC Absolute Y (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Absolute Y (0 - 10): " << (int) cpu._a._value << std::endl;

    // SBC Indirect X 0 - 10
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE1;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0006]._value = 0x10;
    cpu._memory[0x0007]._value = 0x10;
    cpu._memory[0x1010]._value = 0b00001010;

    cpu.reset();
    cpu._x.set(0x01);
    cpu.setCarryFlag(true);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: SBC Indirect X cycles Used (0 - 10): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC Indirect X (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Indirect X (0 - 10): " << (int) cpu._a._value << std::endl;

    // SBC Indirect Y 0 - 10
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xF1;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x10;
    cpu._memory[0x0006]._value = 0x10;
    cpu._memory[0x1011]._value = 0b00001010;

    cpu.reset();
    cpu._y.set(0x01);
    cpu.setCarryFlag(true);
    cpu._a.set(0x00);
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: SBC Indirect Y cycles Used (0 - 10): " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC Indirect Y (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Indirect Y (0 - 10): " << (int) cpu._a._value << std::endl;

    return (0);
}
