/*
 * Emmett
 */

#include "../../include/emmett.h"

int test_LDA(MOS6502 &cpu)
{
    int cyclesUsed = 0;

    /*Exemple for LDA Immediate*/
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA9;
    cpu._memory[0x1001]._value = 0x05;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(2)) != 0)
        std::cerr << "FAILURE: LDA Immediate cycles Used: " << cyclesUsed << " != 0" << std::endl;

    if (cpu._a._value != 0x05) {
        std::cerr << "FAILURE: LDA Immediate: " << (int) cpu._a._value << " != 0x05" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Immediate: " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Zero Page*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA5;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x10;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(3)) != 0)
        std::cerr << "FAILURE: LDA Zero Page cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: LDA Zero Page: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Zero Page: " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA ZeroX Page*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB5;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x000A]._value = 0x10;

    cpu.reset();
    cpu._x.set(0x05);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDA Zero Page X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x10) {
        std::cerr << "FAILURE: LDA Zero Page X: " << (int) cpu._a._value << " != 0x10" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Zero Page X: " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Absolute*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xAD;
    cpu._memory[0x1001]._value = 0xFF;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x10FF]._value = 0x16;

    cpu.reset();
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDA Absolute cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x16) {
        std::cerr << "FAILURE: LDA Absolute: " << (int) cpu._a._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Absolute: " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Absolute X*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xBD;
    cpu._memory[0x1001]._value = 0xFA;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x10FF]._value = 0x16;

    cpu.reset();
    cpu._x.set(0x05);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDA Absolute X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x16) {
        std::cerr << "FAILURE: LDA Absolute X: " << (int) cpu._a._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Absolute X: " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Absolute X (page crossed)*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xBD;
    cpu._memory[0x1001]._value = 0xFA;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1100]._value = 0x16;

    cpu.reset();
    cpu._x.set(0x06);
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: LDA Absolute X (page crossed) cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x16) {
        std::cerr << "FAILURE: LDA Absolute X (page crossed): " << (int) cpu._a._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Absolute X (page crossed): " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Absolute Y*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB9;
    cpu._memory[0x1001]._value = 0xFA;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x10FF]._value = 0x16;

    cpu.reset();
    cpu._y.set(0x05);
    if ((cyclesUsed = cpu.execute(4)) != 0)
        std::cerr << "FAILURE: LDA Absolute Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x16) {
        std::cerr << "FAILURE: LDA Absolute Y: " << (int) cpu._a._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Absolute Y: " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Absolute Y (page crossed)*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB9;
    cpu._memory[0x1001]._value = 0xFA;
    cpu._memory[0x1002]._value = 0x10;
    cpu._memory[0x1100]._value = 0x16;

    cpu.reset();
    cpu._y.set(0x06);
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: LDA Absolute Y (page crossed) cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x16) {
        std::cerr << "FAILURE: LDA Absolute Y (page crossed): " << (int) cpu._a._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Absolute Y (page crossed): " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Indirect X*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA1;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0006]._value = 0x10;
    cpu._memory[0x0007]._value = 0x10;
    cpu._memory[0x1010]._value = 0x16;

    cpu.reset();
    cpu._x.set(0x01);
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: LDA Indirect X cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x16) {
        std::cerr << "FAILURE: LDA Indirect X: " << (int) cpu._a._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Indirect X: " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Indirect Y*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB1;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x10;
    cpu._memory[0x0006]._value = 0x10;
    cpu._memory[0x1011]._value = 0x16;

    cpu.reset();
    cpu._y.set(0x01);
    if ((cyclesUsed = cpu.execute(5)) != 0)
        std::cerr << "FAILURE: LDA Indirect Y cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x16) {
        std::cerr << "FAILURE: LDA Indirect Y: " << (int) cpu._a._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Indirect Y: " << (int) cpu._a._value << std::endl;

    /*Exemple for LDA Indirect Y (page crossed)*/
    cpu.clear();
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xB1;
    cpu._memory[0x1001]._value = 0x05;
    cpu._memory[0x0005]._value = 0x10;
    cpu._memory[0x0006]._value = 0x10;
    cpu._memory[0x1100]._value = 0x16;

    cpu.reset();
    cpu._y.set(0xF0);
    if ((cyclesUsed = cpu.execute(6)) != 0)
        std::cerr << "FAILURE: LDA Indirect Y (page crossed) cycles Used: " << cyclesUsed << " != 0" << std::endl;
    if (cpu._a._value != 0x16) {
        std::cerr << "FAILURE: LDA Indirect Y (page crossed): " << (int) cpu._a._value << " != 0x16" << std::endl;
    } else
        std::cout << "SUCCESS: LDA Indirect Y (page crossed): " << (int) cpu._a._value << std::endl;
    return 0;
}
