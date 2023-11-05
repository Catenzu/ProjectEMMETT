/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_BRK(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // BRK
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0xFFFE]._value = 0x00;
    cpu._memory[0xFFFF]._value = 0x30;
    cpu._memory[0x1000]._value = 0x00;
    cpu._memory[0x3000]._value = 0xA9;
    cpu._memory[0x3001]._value = 0x05;
    cpu._memory[0x3002]._value = 0x40;
    cpu.reset();
    if ((cyclesUsed = cpu.execute(7)) != 0)
        std::cerr << "FAILURE: BRK cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDA cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x05) {
        std::cerr << "FAILURE: LDA: " << (int) cpu._a._value << " != 0x05" << std::endl;
    } else
        std::cout << "SUCCESS: LDA: " << (int) cpu._a._value << std::endl;

    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: RTI cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._pc != 0x1001) {
        std::cerr << "FAILURE: RTI: " << std::hex << (int) cpu._pc << " != 0x1001" << std::endl;
    } else
        std::cout << "SUCCESS: RTI: " << std::hex << (int) cpu._pc << std::endl;
    return 0;
}
