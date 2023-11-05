/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_NOP(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // NOP
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xEA;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: NOP cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._sr._value != 0b00000000) {
        std::cerr << "FAILURE: NOP: " << std::bitset<8>(cpu._sr._value) << " != 0b00000000" << std::endl;
    } else
        std::cout << "SUCCESS: NOP: " << std::bitset<8>(cpu._sr._value) << std::endl;

    if (cpu._pc != 0x1001) {
        std::cerr << "FAILURE: NOP: " << cpu._pc << " != 0x1001" << std::endl;
    } else
        std::cout << "SUCCESS: NOP: " << cpu._pc << std::endl;
    return 0;
}
