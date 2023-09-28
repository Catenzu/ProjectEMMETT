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
    return 1;
}