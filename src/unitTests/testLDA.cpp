/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_LDA(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    /*Exemple for LDA Immediate*/
    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0xA9;
    cpu.memory[0x1001]._value = 0x05;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDA Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;

    if (cpu.a._value != 0x05) {
        std::cerr << "FAILURE: LDA Immediate: " << (int) cpu.a._value << " != 0x05" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Immediate: " << (int) cpu.a._value << std::endl;

    /*Exemple for LDA Zero Page*/
    cpu.clear();
    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0xA5;
    cpu.memory[0x1001]._value = 0x05;
    cpu.memory[0x0005]._value = 0x10;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: LDA Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu.a._value != 0x10) {
        std::cerr << "FAILURE: LDA Zero Page: " << (int) cpu.a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Zero Page: " << (int) cpu.a._value << std::endl;

    /*Exemple for LDA ZeroX Page*/
    cpu.clear();
    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0xB5;
    cpu.memory[0x1001]._value = 0x05;
    cpu.memory[0x000A]._value = 0x10;

    cpu.reset();
    cpu.x.set(0x05);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDA Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu.a._value != 0x10) {
        std::cerr << "FAILURE: LDA Zero Page X: " << (int) cpu.a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Zero Page X: " << (int) cpu.a._value << std::endl;

    /*Exemple for LDA Absolute Page*/
    cpu.clear();
    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0xAD;
    cpu.memory[0x1001]._value = 0xFF;
    cpu.memory[0x1002]._value = 0x10;
    cpu.memory[0x10FF]._value = 0x16;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDA Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu.a._value != 0x16) {
        std::cerr << "FAILURE: LDA Absolute Page: " << (int) cpu.a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Absolute Page: " << (int) cpu.a._value << std::endl;

    return 0;
}
