/*
 * Emmett
 */

#include <bitset>
#include "../../include/emmett.h"

int test_CMP(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // CMP Immediate a = m

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xC9;
    cpu._memory[0x1001]._value = 0x05;

    cpu.reset();
    cpu._a.set(0x05);

    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: CMP Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CMP Immediate: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Immediate: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CMP Immediate a > m

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xC9;
    cpu._memory[0x1001]._value = 0x05;

    cpu.reset();
    cpu._a.set(0x10);

    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: CMP Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: CMP Immediate: " << std::bitset<8>(cpu._sr._value) << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Immediate: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CMP Zero Page

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xC5;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x10;

    cpu.reset();
    cpu._a.set(0x10);

    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: CMP Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CMP Zero Page: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Zero Page: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CMP Zero Page X

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xD5;
    cpu._memory[0x1001]._value = 0x02;
    cpu._memory[0x0005]._value = 0x10;

    cpu.reset();
    cpu._x.set(0x03);
    cpu._a.set(0x10);

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: CMP Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CMP Zero Page X: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Zero Page X: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CMP Absolute

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xCD;
    cpu._memory[0x1001]._value = 0x02;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x2002]._value = 0x10;

    cpu.reset();
    cpu._a.set(0x10);

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: CMP Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CMP Absolute: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Absolute: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CMP Absolute X

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xDD;
    cpu._memory[0x1001]._value = 0x02;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x2005]._value = 0x10;

    cpu.reset();
    cpu._x.set(0x03);
    cpu._a.set(0x10);

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: CMP Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CMP Absolute X: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Absolute X: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CMP Absolute Y

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xD9;
    cpu._memory[0x1001]._value = 0x02;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x2005]._value = 0x10;

    cpu.reset();
    cpu._y.set(0x03);
    cpu._a.set(0x10);

    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: CMP Absolute Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CMP Absolute Y: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Absolute Y: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CMP Indirect X

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xC1;
    cpu._memory[0x1001]._value = 0x08;
    cpu._memory[0x000A]._value = 0x10;
    cpu._memory[0x000B]._value = 0x20;
    cpu._memory[0x2010]._value = 0x10;

    cpu.reset();
    cpu._a.set(0x10);
    cpu._x.set(0x02);

    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: CMP Indirect X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CMP Indirect X: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Indirect X: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CMP Indirect Y

    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xD1;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0x05;
    cpu._memory[0x000B]._value = 0x20;
    cpu._memory[0x2007]._value = 0x10;

    cpu.reset();
    cpu._a.set(0x10);
    cpu._x.set(0x02);

    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: CMP Indirect Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000011) {
        std::cerr << "FAILURE: CMP Indirect Y: " << std::bitset<8>(cpu._sr._value) << " != 0b00000011" << std::endl;
    } else
        std::cout << "SUCCESS: CMP Indirect Y: " << std::bitset<8>(cpu._sr._value) << std::endl;
    return 0;
}
