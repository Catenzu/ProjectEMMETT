/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_STA(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    //zero page
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x85;
    cpu._memory[0x1001]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0x10;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: STA Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x10) {
        std::cerr << "FAILURE: STA Zero Page: " << (int) cpu._memory[0x000A]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STA Zero Page: " << (int) cpu._memory[0x000A]._value << std::endl;
    }

    cpu.clear();
    //zero page x
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x95;
    cpu._memory[0x1001]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0x10;
    cpu._x._value = 0x05;
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: STA Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000F]._value != 0x10) {
        std::cerr << "FAILURE: STA Zero Page X: " << (int) cpu._memory[0x000F]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STA Zero Page X: " << (int) cpu._memory[0x000F]._value << std::endl;
    }

    cpu.clear();
    //absolute
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x8D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0x10;
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: STA Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x0A0A]._value != 0x10) {
        std::cerr << "FAILURE: STA Absolute: " << (int) cpu._memory[0x0A0A]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STA Absolute: " << (int) cpu._memory[0x0A0A]._value << std::endl;
    }

    cpu.clear();
    //absolute x
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x9D;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0x10;
    cpu._x._value = 0x05;
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: STA Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x0A0F]._value != 0x10) {
        std::cerr << "FAILURE: STA Absolute X: " << (int) cpu._memory[0x0A0F]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STA Absolute X: " << (int) cpu._memory[0x0A0F]._value << std::endl;
    }

    cpu.clear();
    //absolute y
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x99;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0x10;
    cpu._y._value = 0x05;
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: STA Absolute Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x0A0F]._value != 0x10) {
        std::cerr << "FAILURE: STA Absolute Y: " << (int) cpu._memory[0x0A0F]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STA Absolute Y: " << (int) cpu._memory[0x0A0F]._value << std::endl;
    }

    cpu.clear();
    //indirect x
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x000A]._value = 0x0A;
    cpu._memory[0x000B]._value = 0x0A;
    cpu._memory[0x1000]._value = 0x81;
    cpu._memory[0x1001]._value = 0x00;
    cpu.reset();
    cpu._a._value = 0x10;
    cpu._x._value = 0x0A;
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: STA Indirect X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x0A0A]._value != 0x10) {
        std::cerr << "FAILURE: STA Indirect X: " << (int) cpu._memory[0x0A0A]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STA Indirect X: " << (int) cpu._memory[0x0A0A]._value << std::endl;
    }

    cpu.clear();
    //indirect y
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x000A]._value = 0x0A;
    cpu._memory[0x000B]._value = 0x0A;
    cpu._memory[0x1000]._value = 0x91;
    cpu._memory[0x1001]._value = 0x0A;
    cpu.reset();
    cpu._a._value = 0x10;
    cpu._y._value = 0x05;
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: STA Indirect Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x0A0F]._value != 0x10) {
        std::cerr << "FAILURE: STA Indirect Y: " << (int) cpu._memory[0x0A0F]._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: STA Indirect Y: " << (int) cpu._memory[0x0A0F]._value << std::endl;
    }
    return 0;
}
