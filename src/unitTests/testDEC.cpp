/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_DEC(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // DEC ZP
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xC6;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0x0A;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: DEC ZP cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x09) {
        std::cerr << "FAILURE: DEC ZP: " << (int) cpu._memory[0x000A]._value << " != 0x09" << std::endl;
    } else
        std::cout << "SUCCESS: DEC ZP: " << (int) cpu._memory[0x000A]._value << std::endl;

    // DEC ZP loop
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xC6;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0x00;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: DEC ZP loop cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0xFF) {
        std::cerr << "FAILURE: DEC ZP loop: " << (int) cpu._memory[0x000A]._value << " != 0xFF" << std::endl;
    } else
        std::cout << "SUCCESS: DEC ZP loop: " << (int) cpu._memory[0x000A]._value << std::endl;

    // DEC ZPX
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xD6;
    cpu._memory[0x1001]._value = 0x09;
    cpu._memory[0x000A]._value = 0x0A;

    cpu.reset();
    cpu._x._value = 0x01;
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: DEC ZPX cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x09) {
        std::cerr << "FAILURE: DEC ZPX: " << (int) cpu._memory[0x000A]._value << " != 0x09" << std::endl;
    } else
        std::cout << "SUCCESS: DEC ZPX: " << (int) cpu._memory[0x000A]._value << std::endl;

    // DEC ABS
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xCE;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x200A]._value = 0x0A;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: DEC ABS cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x200A]._value != 0x09) {
        std::cerr << "FAILURE: DEC ABS: " << (int) cpu._memory[0x200A]._value << " != 0x09" << std::endl;
    } else
        std::cout << "SUCCESS: DEC ABS: " << (int) cpu._memory[0x200A]._value << std::endl;

    // DEC ABSX
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xDE;
    cpu._memory[0x1001]._value = 0x09;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x200A]._value = 0x0A;

    cpu.reset();
    cpu._x._value = 0x01;
    if ((cyclesUsed = cpu.execute(7)) != 0)
        std::cerr << "FAILURE: DEC ABSX cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x200A]._value != 0x09) {
        std::cerr << "FAILURE: DEC ABSX: " << (int) cpu._memory[0x200A]._value << " != 0x09" << std::endl;
    } else
        std::cout << "SUCCESS: DEC ABSX: " << (int) cpu._memory[0x200A]._value << std::endl;

    // DEX
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xCA;

    cpu.reset();
    cpu._x._value = 0x01;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: DEX cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0x00) {
        std::cerr << "FAILURE: DEX: " << (int) cpu._x._value << " != 0x00" << std::endl;
    } else
        std::cout << "SUCCESS: DEX: " << (int) cpu._x._value << std::endl;

    // DEX
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xCA;

    cpu.reset();
    cpu._x._value = 0x00;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: DEX cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0xFF) {
        std::cerr << "FAILURE: DEX: " << (int) cpu._x._value << " != 0xFF" << std::endl;
    } else
        std::cout << "SUCCESS: DEX: " << (int) cpu._x._value << std::endl;

    // DEY
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0x88;

    cpu.reset();
    cpu._y._value = 0x01;
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: DEY cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._y._value != 0x00) {
        std::cerr << "FAILURE: DEY: " << (int) cpu._y._value << " != 0x00" << std::endl;
    } else
        std::cout << "SUCCESS: DEY: " << (int) cpu._y._value << std::endl;
    return 0;
}
