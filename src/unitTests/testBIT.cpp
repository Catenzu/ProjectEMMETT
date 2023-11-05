/*
 * Emmett
 */

#include <bitset>
#include "../../include/emmett.h"

int test_BIT(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // BIT Absolute 00000000 & 00000001
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2C;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1005]._value = 0b00000000;

    cpu.reset();
    cpu._a.set(0b00000001);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: BIT Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000010) {
        std::cerr << "FAILURE: BIT Absolute: " << std::bitset<8>(cpu._sr._value) << " != 0b00000010" << std::endl;
    } else
        std::cout << "SUCCESS: BIT Absolute: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // BIT Absolute 00000001 & 00000001
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2C;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1005]._value = 0b00000001;

    cpu.reset();
    cpu._a.set(0b00000001);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: BIT Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000000) {
        std::cerr << "FAILURE: BIT Absolute: " << std::bitset<8>(cpu._sr._value) << " != 0b00000000" << std::endl;
    } else
        std::cout << "SUCCESS: BIT Absolute: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // BIT Absolute 10000001 & 10000001
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2C;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1005]._value = 0b10000001;

    cpu.reset();
    cpu._a.set(0b10000001);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: BIT Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b10000000) {
        std::cerr << "FAILURE: BIT Absolute: " << std::bitset<8>(cpu._sr._value) << " != 0b10000000" << std::endl;
    } else
        std::cout << "SUCCESS: BIT Absolute: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // BIT Absolute 01000001 & 01000001
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2C;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1005]._value = 0b01000001;

    cpu.reset();
    cpu._a.set(0b01000001);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: BIT Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b01000000) {
        std::cerr << "FAILURE: BIT Absolute: " << std::bitset<8>(cpu._sr._value) << " != 0b01000000" << std::endl;
    } else
        std::cout << "SUCCESS: BIT Absolute: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // BIT ZeroPage 01000001 & 01000001
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x24;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0b01000001;

    cpu.reset();
    cpu._a.set(0b01000001);
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BIT ZeroPage cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b01000000) {
        std::cerr << "FAILURE: BIT ZeroPage: " << std::bitset<8>(cpu._sr._value) << " != 0b01000000" << std::endl;
    } else
        std::cout << "SUCCESS: BIT ZeroPage: " << std::bitset<8>(cpu._sr._value) << std::endl;
    return 0;
}
