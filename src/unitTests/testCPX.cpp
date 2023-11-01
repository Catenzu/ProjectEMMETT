/*
 * Emmett
 */

#include <bitset>
#include "../../include/emmett.h"

int test_CPX(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // CPX Immediate x = m

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE0;
    cpu._memory[0x1001]._value = 0x05;

    cpu.reset();
    cpu._x.set(0x05);

    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: CPX Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CPX Immediate: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CPX Immediate: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CPX Immediate x > m

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE0;
    cpu._memory[0x1001]._value = 0x05;

    cpu.reset();
    cpu._x.set(0x10);

    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: CPX Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: CPX Immediate: " << std::bitset<8>(cpu._sr._value) << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: CPX Immediate: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CPX Zero Page

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE4;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x10;

    cpu.reset();
    cpu._x.set(0x10);

    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: CPX Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CPX Zero Page: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CPX Zero Page: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CPX Absolute

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xEC;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1005]._value = 0x10;

    cpu.reset();
    cpu._x.set(0x10);

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: CPX Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CPX Absolute: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CPX Absolute: " << std::bitset<8>(cpu._sr._value) << std::endl;
    return 0;
}
