/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_LDY(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    /*Exemple for LDY Immediate*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA0;
    cpu._memory[0x1001]._value = 0x05;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDY Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;

    if (cpu._y._value != 0x05) {
        std::cerr << "FAILURE: LDY Immediate: " << (int) cpu._y._value << " != 0x05" << std::endl;
    } else
        std::cout << "SUCCESS: LDY Immediate: " << (int) cpu._y._value << std::endl;

    /*Exemple for LDY Zero Page*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA4;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x10;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: LDY Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._y._value != 0x10) {
        std::cerr << "FAILURE: LDY Zero Page: " << (int) cpu._y._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDY Zero Page: " << (int) cpu._y._value << std::endl;

    /*Exemple for LDY ZeroX Page*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB4;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x000A]._value = 0x10;

    cpu.reset();
    cpu._x.set(0x05);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDY Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._y._value != 0x10) {
        std::cerr << "FAILURE: LDY Zero Page X: " << (int) cpu._y._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDY Zero Page X: " << (int) cpu._y._value << std::endl;

    /*Exemple for LDY Absolute*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xAC;
    cpu._memory[0x1001]._value = 0xAA;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x10AA]._value = 0x10;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDY Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._y._value != 0x10) {
        std::cerr << "FAILURE: LDY Absolute: " << (int) cpu._y._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDY Absolute: " << (int) cpu._y._value << std::endl;

    /*Exemple for LDY AbsoluteX*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xBC;
    cpu._memory[0x1001]._value = 0xAA;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x10AF]._value = 0x10;

    cpu.reset();
    cpu._x.set(0x05);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDY Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._y._value != 0x10) {
        std::cerr << "FAILURE: LDY Absolute X: " << (int) cpu._y._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDY Absolute X: " << (int) cpu._y._value << std::endl;

    return 0;
}
