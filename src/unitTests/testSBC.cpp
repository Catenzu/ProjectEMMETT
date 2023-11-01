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
    if (cpu.execute(2) != 0)
        std::cerr << "FAILURE: SBC Immediate cycles Used (0 - 0): " << cpu.execute(2) << " != 0" << std::endl;
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
    if (cpu.execute(2) != 0)
        std::cerr << "FAILURE: SBC Immediate cycles Used (0 - 0 - 1): " << cpu.execute(2) << " != 0" << std::endl;
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
    if (cpu.execute(2) != 0)
        std::cerr << "FAILURE: SBC Immediate cycles Used (0 - 10): " << cpu.execute(2) << " != 0" << std::endl;
    if (cpu._a._value != 0b11110110) {
        std::cerr << "FAILURE: SBC Immediate (0 - 10): " << std::bitset<8>(cpu._a._value) << " != 0b11110110" << std::endl;
    } else
        std::cout << "SUCCESS: SBC Immediate (0 - 10): " << (int) cpu._a._value << std::endl;

    return (0);
}
