/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_TRANSFER(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    //zero page
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xAA;
    cpu._memory[0x1001]._value = 0xA8;
    cpu.reset();
    cpu._a._value = 0x10;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: TAX cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if ((cyclesUsed = cpu.execute(2)) != 0)
    std::cerr << "FAILURE: TAY cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0x10) {
        std::cerr << "FAILURE: TAX and TAY: " << (int) cpu._x._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: TAX and TAY: " << (int) cpu._x._value << std::endl;
    }
    if (cpu._y._value != 0x10) {
        std::cerr << "FAILURE: TAX and TAY: " << (int) cpu._y._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: TAX and TAY: " << (int) cpu._y._value << std::endl;
    }

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x98;
    cpu.reset();
    cpu._y._value = 0x10;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: TYA cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: TYA: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: TYA: " << (int) cpu._a._value << std::endl;
    }

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x8A;
    cpu.reset();
    cpu._x._value = 0x10;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: TXA cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: TXA: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: TXA: " << (int) cpu._a._value << std::endl;
    }
    return 0;
}
