/*
 * Emmett
 */

#include "../include/emmett.h"

void MOS6502::BCC(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle
    int valueSigned = (int) value;

    if (valueSigned > 127)
        valueSigned -= 256;

    if (!(_sr._value & 0b00000001)) {
        uint16_t oldAddress = _pc;
        _pc += valueSigned;
        if ((oldAddress & 0xFF00) != (_pc & 0xFF00)) //page crossed
            cycles--;
        cycles--;
    }
    if (_debugPrint)
        std::cout << "--BCC: " << valueSigned << std::endl;
}

void MOS6502::BCS(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle
    int valueSigned = (int) value;

    if (valueSigned > 127)
        valueSigned -= 256;

    if ((_sr._value & 0b00000001)) {
        uint16_t oldAddress = _pc;
        _pc += valueSigned;
        if ((oldAddress & 0xFF00) != (_pc & 0xFF00)) //page crossed
            cycles--;
        cycles--;
    }
    if (_debugPrint)
        std::cout << "--BCS: " << valueSigned << std::endl;
}

void MOS6502::BEQ(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle
    int valueSigned = (int) value;

    if (valueSigned > 127)
        valueSigned -= 256;

    if ((_sr._value & 0b00000010)) {
        uint16_t oldAddress = _pc;
        _pc += valueSigned;
        if ((oldAddress & 0xFF00) != (_pc & 0xFF00)) //page crossed
            cycles--;
        cycles--;
    }
    if (_debugPrint)
        std::cout << "--BEQ: " << valueSigned << std::endl;
}

void MOS6502::BMI(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle
    int valueSigned = (int) value;

    if (valueSigned > 127)
        valueSigned -= 256;

    if ((_sr._value & 0b10000000)) {
        uint16_t oldAddress = _pc;
        _pc += valueSigned;
        if ((oldAddress & 0xFF00) != (_pc & 0xFF00)) //page crossed
            cycles--;
        cycles--;
    }
    if (_debugPrint)
        std::cout << "--BMI: " << valueSigned << std::endl;
}

void MOS6502::BNE(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle
    int valueSigned = (int) value;

    if (valueSigned > 127)
        valueSigned -= 256;

    if (!(_sr._value & 0b00000010)) {
        uint16_t oldAddress = _pc;
        _pc += valueSigned;
        if ((oldAddress & 0xFF00) != (_pc & 0xFF00)) //page crossed
            cycles--;
        cycles--;
    }
    if (_debugPrint)
        std::cout << "--BNE: " << valueSigned << std::endl;
}

void MOS6502::BPL(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle
    int valueSigned = (int) value;

    if (valueSigned > 127)
        valueSigned -= 256;

    if (!(_sr._value & 0b10000000)) {
        uint16_t oldAddress = _pc;
        _pc += valueSigned;
        if ((oldAddress & 0xFF00) != (_pc & 0xFF00)) //page crossed
            cycles--;
        cycles--;
    }
    if (_debugPrint)
        std::cout << "--BPL: " << valueSigned << std::endl;
}

void MOS6502::BVC(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle
    int valueSigned = (int) value;

    if (valueSigned > 127)
        valueSigned -= 256;

    if (!(_sr._value & 0b01000000)) {
        uint16_t oldAddress = _pc;
        _pc += valueSigned;
        if ((oldAddress & 0xFF00) != (_pc & 0xFF00)) //page crossed
            cycles--;
        cycles--;
    }
    if (_debugPrint)
        std::cout << "--BVC: " << valueSigned << std::endl;
}

void MOS6502::BVS(int &cycles)
{
    unsigned char value = fetch(cycles); //1cycle
    int valueSigned = (int) value;

    if (valueSigned > 127)
        valueSigned -= 256;

    if ((_sr._value & 0b01000000)) {
        uint16_t oldAddress = _pc;
        _pc += valueSigned;
        if ((oldAddress & 0xFF00) != (_pc & 0xFF00)) //page crossed
            cycles--;
        cycles--;
    }
    if (_debugPrint)
        std::cout << "--BVS: " << valueSigned << std::endl;
}
