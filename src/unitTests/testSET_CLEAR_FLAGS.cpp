/*
 * Emmett
 */

#include <bitset>
#include "../../include/emmett.h"

int test_SET_CLEAR_FLAGS(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // SEC
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x38;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: SEC cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: SEC: " << std::bitset<8>(cpu._sr._value) << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: SEC: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // SED
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xF8;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: SED cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00001000) {
        std::cerr << "FAILURE: SED: " << std::bitset<8>(cpu._sr._value) << " != 0b00001000" << std::endl;
    } else
        std::cout << "SUCCESS: SED: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // SEI
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x78;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: SEI cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000100) {
        std::cerr << "FAILURE: SEI: " << std::bitset<8>(cpu._sr._value) << " != 0b00000100" << std::endl;
    } else
        std::cout << "SUCCESS: SEI: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CLC
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x18;

    cpu.reset();
    cpu._sr.set(0b00000001);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: CLC cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000000) {
        std::cerr << "FAILURE: CLC: " << std::bitset<8>(cpu._sr._value) << " != 0b00000000" << std::endl;
    } else
        std::cout << "SUCCESS: CLC: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CLD
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xD8;

    cpu.reset();
    cpu._sr.set(0b00001000);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: CLD cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000000) {
        std::cerr << "FAILURE: CLD: " << std::bitset<8>(cpu._sr._value) << " != 0b00000000" << std::endl;
    } else
        std::cout << "SUCCESS: CLD: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CLI
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x58;

    cpu.reset();
    cpu._sr.set(0b00000100);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: CLI cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000000) {
        std::cerr << "FAILURE: CLI: " << std::bitset<8>(cpu._sr._value) << " != 0b00000000" << std::endl;
    } else
        std::cout << "SUCCESS: CLI: " << std::bitset<8>(cpu._sr._value) << std::endl;

    // CLV
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB8;

    cpu.reset();
    cpu._sr.set(0b01000000);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: CLV cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000000) {
        std::cerr << "FAILURE: CLV: " << std::bitset<8>(cpu._sr._value) << " != 0b00000000" << std::endl;
    } else
        std::cout << "SUCCESS: CLV: " << std::bitset<8>(cpu._sr._value) << std::endl;

    return 0;
}
