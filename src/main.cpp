/*
 * Emmett
 */

#include "../include/emmett.h"

int main()
{
    MOS6502 cpu;

    if (unitTests())
        return 0;

    /*//Exemple for LDA Immediate
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA9;
    cpu._memory[0x1001]._value = 0x05;
    */

    /*Exemple for ADC Immediate*/
    cpu._memory[0xFFFC]._value = 0x00;
    cpu._memory[0xFFFD]._value = 0x10;
    cpu._memory[0x1000]._value = 0xA9;
    cpu._memory[0x1001]._value = 0x0A;


    cpu.reset();
    cpu.execute(2);
    return 0;
}