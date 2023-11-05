/*
 * Emmett
 */

#include "../../include/emmett.h"
#include "../../include/unitTests/unitTests.h"

int unitTests()
{
    MOS6502 cpu;

    cpu._isInDebugMode = true;
    test_LDA(cpu);
    std::cout << "------------------------------" << std::endl;
    test_LDX(cpu);
    std::cout << "------------------------------" << std::endl;
    test_LDY(cpu);
    std::cout << "------------------------------" << std::endl;
    test_ADC(cpu);
    std::cout << "------------------------------" << std::endl;
    test_AND(cpu);
    std::cout << "------------------------------" << std::endl;
    test_ASL(cpu);
    std::cout << "------------------------------" << std::endl;
    test_STA(cpu);
    std::cout << "------------------------------" << std::endl;
    test_STX(cpu);
    std::cout << "------------------------------" << std::endl;
    test_STY(cpu);
    std::cout << "------------------------------" << std::endl;
    test_TRANSFER(cpu);
    std::cout << "------------------------------" << std::endl;
    test_PUSHPULL(cpu);
    std::cout << "------------------------------" << std::endl;
    test_JMP(cpu);
    std::cout << "------------------------------" << std::endl;
    test_ROL(cpu);
    std::cout << "------------------------------" << std::endl;
    test_ROR(cpu);
    std::cout << "------------------------------" << std::endl;
    test_BRANCH(cpu);
    std::cout << "------------------------------" << std::endl;
    test_CMP(cpu);
    std::cout << "------------------------------" << std::endl;
    test_CPX(cpu);
    std::cout << "------------------------------" << std::endl;
    test_CPY(cpu);
    std::cout << "------------------------------" << std::endl;
    test_SBC(cpu);
    std::cout << "------------------------------" << std::endl;
    test_SET_CLEAR_FLAGS(cpu);
    std::cout << "------------------------------" << std::endl;
    test_BIT(cpu);
    std::cout << "------------------------------" << std::endl;
    test_EOR(cpu);
    std::cout << "------------------------------" << std::endl;
    test_ORA(cpu);
    std::cout << "------------------------------" << std::endl;
    test_NOP(cpu);
    return 1;
}