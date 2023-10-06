/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_LDX(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    /*Exemple for LDX Immediate*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA2;
    cpu._memory[0x1001]._value = 0x05;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDX Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;

    if (cpu._x._value != 0x05) {
        std::cerr << "FAILURE: LDX Immediate: " << (int) cpu._x._value << " != 0x05" << std::endl;
    } else
        std::cout << "SUCCESS: LDX Immediate: " << (int) cpu._x._value << std::endl;

    /*Exemple for LDX Zero Page*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA6;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x10;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: LDX Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0x10) {
        std::cerr << "FAILURE: LDX Zero Page: " << (int) cpu._x._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDX Zero Page: " << (int) cpu._x._value << std::endl;

    /*Exemple for LDX ZeroY Page*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB6;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x000A]._value = 0x10;

    cpu.reset();
    cpu._y.set(0x05);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDX Zero Page Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0x10) {
        std::cerr << "FAILURE: LDX Zero Page Y: " << (int) cpu._x._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDX Zero Page Y: " << (int) cpu._x._value << std::endl;

    /*Exemple for LDX ZeroY looping*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB6;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0004]._value = 0x10;

    cpu.reset();
    cpu._y.set(0xFF);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDX Zero Page Y looping cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0x10) {
        std::cerr << "FAILURE: LDX Zero Page Y looping: " << (int) cpu._x._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDX Zero Page Y looping: " << (int) cpu._x._value << std::endl;

    /*Exemple for LDX Absolute*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xAE;
    cpu._memory[0x1001]._value = 0xFF;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x10FF]._value = 0x16;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDX Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0x16) {
        std::cerr << "FAILURE: LDX Absolute: " << (int) cpu._x._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDX Absolute: " << (int) cpu._x._value << std::endl;

    /*Exemple for LDX AbsoluteY*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xBE;
    cpu._memory[0x1001]._value = 0xFA;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x10FF]._value = 0x16;

    cpu.reset();
    cpu._y.set(0x05);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDX Absolute Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0x16) {
        std::cerr << "FAILURE: LDX Absolute Y: " << (int) cpu._x._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDX Absolute Y: " << (int) cpu._x._value << std::endl;
    return 0;
}
