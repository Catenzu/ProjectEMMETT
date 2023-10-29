/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_BRANCH(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    //Branching if Carry Clear
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x90;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0x00;
     if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BCC cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BCC: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BCC: " << (int) cpu._a._value << std::endl;

    //Branching if Carry Clear not taken
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x90;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0b00000001;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: BCC not taken cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x05) {
        std::cerr << "FAILURE: BCC not taken: " << (int) cpu._a._value << " != 0x05" << std::endl;
    } else
        std::cout << "SUCCESS: BCC not taken: " << (int) cpu._a._value << std::endl;

    //Branching if Carry Clear page crossed
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0xF0;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x10F0]._value = 0x90;
    cpu._memory[0x10F1]._value = 0x10;
    cpu._memory[0x10F2]._value = 0xA9;
    cpu._memory[0x10F3]._value = 0x05;
    cpu._memory[0x1102]._value = 0xA9;
    cpu._memory[0x1103]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0x00;
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: BCC page crossed cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BCC page crossed: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BCC page crossed: " << (int) cpu._a._value << std::endl;

    //Branching if Carry Set
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB0;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0b00000001;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BCS cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BCS: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BCS: " << (int) cpu._a._value << std::endl;

    //Branching if Equal
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xF0;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0b00000010;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BEQ cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BEQ: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BEQ: " << (int) cpu._a._value << std::endl;

    //Branching if Minus
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x30;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0b10000000;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BMI cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BMI: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BMI: " << (int) cpu._a._value << std::endl;

    //Branching if Not Equal
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xD0;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0b10000001;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BNE cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BNE: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BNE: " << (int) cpu._a._value << std::endl;

    //Branching if Positive
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x10;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0b00000011;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BNE cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BNE: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BNE: " << (int) cpu._a._value << std::endl;

    //Branching if Overflow clear
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x50;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0b10000011;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BVC cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BVC: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BVC: " << (int) cpu._a._value << std::endl;

    //Branching if Overflow set
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x70;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0xA9;
    cpu._memory[0x1003]._value = 0x05;
    cpu._memory[0x100C]._value = 0xA9;
    cpu._memory[0x100D]._value = 0x10;
    cpu.reset();
    cpu._sr._value = 0b01000000;
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: BVS cycles Used: " << cyclesUsed << " != 0" << std::endl;
    cpu.execute(2);
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: BVS: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: BVS: " << (int) cpu._a._value << std::endl;
    return 0;
}
