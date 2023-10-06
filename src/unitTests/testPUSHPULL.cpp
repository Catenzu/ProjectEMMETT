/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_PUSHPULL(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x48;
    cpu._memory[0x1001]._value = 0x68;
    cpu.reset();
    cpu._a._value = 0x10;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: PHA cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu._a._value = 0x00;
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: PLA cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: PLA: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: PLA: " << (int) cpu._a._value << std::endl;
    }

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x08;
    cpu._memory[0x1001]._value = 0x28;
    cpu.reset();
    cpu._sr._value = 0x10;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: PHP cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu._sr._value = 0x00;
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: PLP cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0x10) {
        std::cerr << "FAILURE: PLP: " << (int) cpu._sr._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: PLP: " << (int) cpu._sr._value << std::endl;
    }
    return 0;
}
