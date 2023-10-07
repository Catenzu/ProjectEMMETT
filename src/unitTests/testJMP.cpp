/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_JMP(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    //jump absolute
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x4C;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1003]._value = 0xA9;
    cpu._memory[0x1004]._value = 0x05;
    cpu._memory[0x1005]._value = 0xA9;
    cpu._memory[0x1006]._value = 0x10;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: JMP Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDA after Jump Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: JMP Absolute: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: JMP Absolute: " << (int) cpu._a._value << std::endl;
    }

    //jump indirect
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x6C;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1003]._value = 0xA9;
    cpu._memory[0x1004]._value = 0x05;
    cpu._memory[0x1005]._value = 0x00;
    cpu._memory[0x1006]._value = 0x40;
    cpu._memory[0x4000]._value = 0xA9;
    cpu._memory[0x4001]._value = 0x10;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: JMP Indirect cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDA after Jump Indirect cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: JMP Indirect: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: JMP Indirect: " << (int) cpu._a._value << std::endl;
    }

    //subroutine
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x20;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x1003]._value = 0xA9;
    cpu._memory[0x1004]._value = 0x05;
    cpu._memory[0x2005]._value = 0xA9;
    cpu._memory[0x2006]._value = 0x10;
    cpu._memory[0x2007]._value = 0x60;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: JSR Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDA after JSR Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: JSR Absolute: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: JSR Absolute: " << (int) cpu._a._value << std::endl;
    }
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: RTS cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDA after RTS cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x05) {
        std::cerr << "FAILURE: RTS: " << (int) cpu._a._value << " != 0x05" << std::endl;
    } else {
        std::cout << "SUCCESS: RTS: " << (int) cpu._a._value << std::endl;
    }

    //test if computing bug is there in Jump Indirect
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x6C;
    cpu._memory[0x1001]._value = 0xFF;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x1003]._value = 0xA9;
    cpu._memory[0x1004]._value = 0x05;
    /*expected location at 20FF-2000 and not 20FF-2100*/
    cpu._memory[0x20FF]._value = 0x00;
    cpu._memory[0x2000]._value = 0x40;
    cpu._memory[0x2100]._value = 0x30;

    cpu._memory[0x3000]._value = 0xA9;
    cpu._memory[0x3001]._value = 0x1F;
    cpu._memory[0x4000]._value = 0xA9;
    cpu._memory[0x4001]._value = 0x10;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: JMP Indirect (HW bug) cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDA after Jump Indirect (HW bug) cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: JMP Indirect (HW bug): " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else {
        std::cout << "SUCCESS: JMP Indirect (HW bug): " << (int) cpu._a._value << std::endl;
    }
    return 0;
}
