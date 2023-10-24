/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_ROL(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    /*Exemple for ROL Accumulator*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2A;

    cpu.reset();
    cpu.setCarryFlag(true);
    cpu._a.set(0b00110000);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ROL Accumulator cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b01100001) {
        std::cerr << "FAILURE: ROL Accumulator: " << (int) cpu._a._value << " != 0b01100001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Accumulator: " << (int) cpu._a._value << std::endl;


    /*Exemple for ROL Accumulator carry flag set*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x2A;

    cpu.reset();
    cpu.setCarryFlag(true);
    cpu._a.set(0b10110100);
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: ROL Accumulator cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0b01101001) {
        std::cerr << "FAILURE: ROL Accumulator: " << (int) cpu._a._value << " != 0b01101001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Accumulator: " << (int) cpu._a._value << std::endl;
    if (cpu._sr._value != 0b00000001) {
        std::cerr << "FAILURE: ROL Accumulator carry flag: " << (int) cpu._sr._value << " != 0b00000001" << std::endl;
    } else
        std::cout << "SUCCESS: ROL Accumulator carry flag: " << (int) cpu._sr._value << std::endl;
    return 0;
}
