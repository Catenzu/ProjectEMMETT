/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_STX(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    //zero page
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x86;
    cpu._memory[0x1001]._value = 0x0A;
    cpu.reset();
    cpu._x._value = 0x10;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: STX Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x10) {
        std::cerr << "FAILURE: STX Zero Page: " << (int) cpu._memory[0x000A]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STX Zero Page: " << (int) cpu._memory[0x000A]._value << std::endl;
    }

    cpu.clear();
    //zero page y
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x96;
    cpu._memory[0x1001]._value = 0x0A;
    cpu.reset();
    cpu._x._value = 0x10;
    cpu._y._value = 0x05;
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: STX Zero Page Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000F]._value != 0x10) {
        std::cerr << "FAILURE: STX Zero Page Y: " << (int) cpu._memory[0x000F]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STX Zero Page Y: " << (int) cpu._memory[0x000F]._value << std::endl;
    }

    cpu.clear();
    //absolute
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x8E;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x0A;
    cpu.reset();
    cpu._x._value = 0x10;
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: STX Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x0A0A]._value != 0x10) {
        std::cerr << "FAILURE: STX Absolute: " << (int) cpu._memory[0x0A0A]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STX Absolute: " << (int) cpu._memory[0x0A0A]._value << std::endl;
    }
    return 0;
}
