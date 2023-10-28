/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_ROL(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    /*Exemple for ROL Accumulator*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2A;

    cpu.reset();
    cpu.setCarryFlag(true);
    cpu._a.set(0b00110000);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ROL Accumulator cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b01100001) {
        std::cerr << "FAILURE: ROL Accumulator: " << (int) cpu._a._value << " != 0b01100001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Accumulator: " << (int) cpu._a._value << std::endl;


    /*Exemple for ROL Accumulator carry flag set*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2A;

    cpu.reset();
    cpu.setCarryFlag(true);
    cpu._a.set(0b10110100);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ROL Accumulator cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b01101001) {
        std::cerr << "FAILURE: ROL Accumulator: " << (int) cpu._a._value << " != 0b01101001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Accumulator: " << (int) cpu._a._value << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: ROL Accumulator carry flag: " << (int) cpu._sr._value << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Accumulator carry flag: " << (int) cpu._sr._value << std::endl;

    /*Exemple for ROL Zero Page*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x26;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x0010]._value = 0b10110100;

    cpu.reset();
    cpu.setCarryFlag(true);
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: ROL Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x0010]._value != 0b01101001) {
        std::cerr << "FAILURE: ROL Zero Page: " << (int) cpu._memory[0x0010]._value << " != 0b01101001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Zero Page: " << (int) cpu._memory[0x0010]._value << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: ROL Zero Page carry flag: " << (int) cpu._sr._value << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Zero Page carry flag: " << (int) cpu._sr._value << std::endl;

    /*Exemple for ROL Zero Page X*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x36;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x001A]._value = 0b10110100;

    cpu.reset();
    cpu._x._value = 0x0A;
    cpu.setCarryFlag(true);
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: ROL Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x001A]._value != 0b01101001) {
        std::cerr << "FAILURE: ROL Zero Page X: " << (int) cpu._memory[0x001A]._value << " != 0b01101001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Zero Page X: " << (int) cpu._memory[0x001A]._value << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: ROL Zero Page X carry flag: " << (int) cpu._sr._value << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Zero Page X carry flag: " << (int) cpu._sr._value << std::endl;

    /*Exemple for ROL Absolute*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2E;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x1002]._value = 0x30;
    cpu._memory[0x3010]._value = 0b10110100;

    cpu.reset();
    cpu.setCarryFlag(true);
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: ROL Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x3010]._value != 0b01101001) {
        std::cerr << "FAILURE: ROL Absolute: " << (int) cpu._memory[0x3010]._value << " != 0b01101001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Absolute: " << (int) cpu._memory[0x3010]._value << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: ROL Absolute carry flag: " << (int) cpu._sr._value << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Absolute carry flag: " << (int) cpu._sr._value << std::endl;

    /*Exemple for ROL Absolute X*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x3E;
    cpu._memory[0x1001]._value = 0x10;
    cpu._memory[0x1002]._value = 0x30;
    cpu._memory[0x301A]._value = 0b10110100;

    cpu.reset();
    cpu._x._value = 0x0A;
    cpu.setCarryFlag(true);
    if ((cyclesUsed = cpu.execute(7)) != 0)
        std::cerr << "FAILURE: ROL Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x301A]._value != 0b01101001) {
        std::cerr << "FAILURE: ROL Absolute X: " << (int) cpu._memory[0x301A]._value << " != 0b01101001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Absolute X: " << (int) cpu._memory[0x301A]._value << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: ROL Absolute X carry flag: " << (int) cpu._sr._value << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Absolute X carry flag: " << (int) cpu._sr._value << std::endl;
    return 0;
}
