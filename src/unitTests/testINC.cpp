/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_INC(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    // INC ZP
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE6;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0x0A;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: INC ZP cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x0B) {
        std::cerr << "FAILURE: INC ZP: " << (int) cpu._memory[0x000A]._value << " != 0x0B" << std::endl;
    } else
        std::cout << "SUCCESS: INC ZP: " << (int) cpu._memory[0x000A]._value << std::endl;

    // INC ZP loop
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE6;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x000A]._value = 0xFF;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: INC ZP loop cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x00) {
        std::cerr << "FAILURE: INC ZP loop: " << (int) cpu._memory[0x000A]._value << " != 0x00" << std::endl;
    } else
        std::cout << "SUCCESS: INC ZP loop: " << (int) cpu._memory[0x000A]._value << std::endl;

    // INC ZPX
    cpu.clear();

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xF6;
    cpu._memory[0x1001]._value = 0x09;
    cpu._memory[0x000A]._value = 0x0A;

    cpu.reset();
    cpu._x._value = 0x01;
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: INC ZPX cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x000A]._value != 0x0B) {
        std::cerr << "FAILURE: INC ZPX: " << (int) cpu._memory[0x000A]._value << " != 0x0B" << std::endl;
    } else
        std::cout << "SUCCESS: INC ZPX: " << (int) cpu._memory[0x000A]._value << std::endl;

    // INC ABS
    cpu.clear();

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xEE;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x200A]._value = 0x0A;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: INC ABS cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x200A]._value != 0x0B) {
        std::cerr << "FAILURE: INC ABS: " << (int) cpu._memory[0x200A]._value << " != 0x0B" << std::endl;
    } else
        std::cout << "SUCCESS: INC ABS: " << (int) cpu._memory[0x200A]._value << std::endl;

    // INC ABSX
    cpu.clear();

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xFE;
    cpu._memory[0x1001]._value = 0x0A;
    cpu._memory[0x1002]._value = 0x20;
    cpu._memory[0x200B]._value = 0x0A;

    cpu.reset();
    cpu._x._value = 0x01;

    if ((cyclesUsed = cpu.execute(7)) != 0)
        std::cerr << "FAILURE: INC ABSX cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._memory[0x200B]._value != 0x0B) {
        std::cerr << "FAILURE: INC ABSX: " << (int) cpu._memory[0x200B]._value << " != 0x0B" << std::endl;
    } else
        std::cout << "SUCCESS: INC ABSX: " << (int) cpu._memory[0x200B]._value << std::endl;

    // INX
    cpu.clear();

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xE8;

    cpu.reset();
    cpu._x._value = 0x01;

    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: INX cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._x._value != 0x02) {
        std::cerr << "FAILURE: INX: " << (int) cpu._x._value << " != 0x02" << std::endl;
    } else
        std::cout << "SUCCESS: INX: " << (int) cpu._x._value << std::endl;

    // INY
    cpu.clear();

    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xC8;

    cpu.reset();
    cpu._y._value = 0x01;

    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: INY cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._y._value != 0x02) {
        std::cerr << "FAILURE: INY: " << (int) cpu._y._value << " != 0x02" << std::endl;
    } else
        std::cout << "SUCCESS: INY: " << (int) cpu._y._value << std::endl;
    return 0;
}
