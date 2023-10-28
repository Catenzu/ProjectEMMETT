/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_ROR(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    /*Exemple for ROR Accumulator*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x6A;

    cpu.reset();
    cpu.setCarryFlag(true);
    cpu._a.set(0b00110000);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ROR Accumulator cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b10011000) {
        std::cerr << "FAILURE: ROR Accumulator: " << (int) cpu._a._value << " != 0b10011000" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Accumulator: " << (int) cpu._a._value << std::endl;

    /*Exemple for ROR Accumulator carry flag set*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x6A;

    cpu.reset();
    cpu.setCarryFlag(true);
    cpu._a.set(0b10110101);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ROR Accumulator cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b11011010) {
        std::cerr << "FAILURE: ROR Accumulator: " << (int) cpu._a._value << " != 0b11011010" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Accumulator: " << (int) cpu._a._value << std::endl;
    if (cpu._sr._value != 0b10000001) {
        std::cerr << "FAILURE: ROR Accumulator carry flag: " << (int) cpu._sr._value << " != 0b10000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Accumulator carry flag: " << (int) cpu._sr._value << std::endl;

    /*Exemple for ROR Zero Page*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x66;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x0010]._value = 0b10110101;

    cpu.reset();
    cpu.setCarryFlag(true);
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: ROR Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x0010]._value != 0b11011010) {
        std::cerr << "FAILURE: ROR Zero Page: " << (int) cpu._memory[0x0010]._value << " != 0b11011010" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Zero Page: " << (int) cpu._memory[0x0010]._value << std::endl;
    if (cpu._sr._value != 0b10000001) {
        std::cerr << "FAILURE: ROR Zero Page carry flag: " << (int) cpu._sr._value << " != 0b10000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Zero Page carry flag: " << (int) cpu._sr._value << std::endl;

    /*Exemple for ROR Zero Page X*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x76;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x001A]._value = 0b10110101;

    cpu.reset();
    cpu._x._value = 0x0A;
    cpu.setCarryFlag(true);
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: ROR Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x001A]._value != 0b11011010) {
        std::cerr << "FAILURE: ROR Zero Page X: " << (int) cpu._memory[0x001A]._value << " != 0b11011010" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Zero Page X: " << (int) cpu._memory[0x001A]._value << std::endl;
    if (cpu._sr._value != 0b10000001) {
        std::cerr << "FAILURE: ROR Zero Page X carry flag: " << (int) cpu._sr._value << " != 0b10000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Zero Page X carry flag: " << (int) cpu._sr._value << std::endl;

    /*Exemple for ROR Absolute*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x6E;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x1002]._value = 0x30;
    cpu._memory[0x3010]._value = 0b10110101;

    cpu.reset();
    cpu.setCarryFlag(true);
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: ROR Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x3010]._value != 0b11011010) {
        std::cerr << "FAILURE: ROR Absolute: " << (int) cpu._memory[0x3010]._value << " != 0b11011010" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Absolute: " << (int) cpu._memory[0x3010]._value << std::endl;
    if (cpu._sr._value != 0b10000001) {
        std::cerr << "FAILURE: ROR Absolute carry flag: " << (int) cpu._sr._value << " != 0b10000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Absolute carry flag: " << (int) cpu._sr._value << std::endl;

    /*Exemple for ROR Absolute X*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x7E;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x1002]._value = 0x30;
    cpu._memory[0x301A]._value = 0b10110101;

    cpu.reset();
    cpu._x._value = 0x0A;
    cpu.setCarryFlag(true);
    if ((cyclesUsed = cpu.execute(7)) != 0)
        std::cerr << "FAILURE: ROR Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x301A]._value != 0b11011010) {
        std::cerr << "FAILURE: ROR Absolute X: " << (int) cpu._memory[0x301A]._value << " != 0b11011010" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Absolute X: " << (int) cpu._memory[0x301A]._value << std::endl;
    if (cpu._sr._value != 0b10000001) {
        std::cerr << "FAILURE: ROR Absolute X carry flag: " << (int) cpu._sr._value << " != 0b10000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROR Absolute X carry flag: " << (int) cpu._sr._value << std::endl;
    return 0;
}
