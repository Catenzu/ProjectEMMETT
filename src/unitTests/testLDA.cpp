/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_LDA(MOS6502 &cpu)
{
    /*Exemple for LDA Immediate*/
    cpu.memory[0xFFFC]._value = 0x00;
    cpu.memory[0xFFFD]._value = 0x10;
    cpu.memory[0x1000]._value = 0xA9;
    cpu.memory[0x1001]._value = 0x05;

    cpu.reset();
    cpu.execute(2);

    if (cpu.a._value != 0x05) {
        std::cerr << "LDA Immediate: " << (int) cpu.a._value << " != 0x05" << std::endl;
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
    cpu.execute(3);

    if (cpu.a._value != 0x10) {
        std::cerr << "LDA Zero Page: " << (int) cpu.a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Zero Page: " << (int) cpu.a._value << std::endl;
}
