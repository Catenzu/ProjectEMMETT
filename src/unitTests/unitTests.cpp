/*
 * Emmett
 */

#include "../../include/emmett.h"
#include "../../include/unitTests/unitTests.h"

int unitTests()
{
    MOS6502 cpu;

    test_LDA(cpu);
    test_ADC(cpu);
    test_AND(cpu);
    return 1;
}