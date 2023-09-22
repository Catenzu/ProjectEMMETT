/*
 * Emmett
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>

int unitTests();

class Register {
public:
    Register();

    void set(unsigned char value);

    unsigned char _value;
};

class MOS6502 {
public:
    MOS6502();

    void clear();
    void reset();
    int execute(int cycles);
    unsigned char aluAddition(unsigned char componentA, unsigned char componentB, int &cycles);
    bool _aluAdditionCarry; //not the carry flag, but the carry of the addition
    unsigned char fetch(int &cycles);
    unsigned char getMemory(uint16_t address, int &cycles);

    /*inDebug*/
    bool _isInDebugMode;

    /*Register*/
    Register _a; //Accumulator
    Register _x;
    Register _y;
    Register _sp; //Stack Pointer
    Register _sr; //Status Register
    uint16_t _pc; //Program Counter

    /*Memory*/
    void setMemory(uint16_t address, unsigned char value);
    Register _memory[65536];

    /*Status Register*/
    void setZeroFlag(unsigned char value);
    void setNegativeFlag(unsigned char value);

    /*Opcode*/
    void ADC_IM(int &cycles);
    void LDA_IM(int &cycles);
    void LDA_ZERO(int &cycles);
    void LDA_ZEROX(int &cycles);
    void LDA_ABS(int &cycles);
    void LDA_ABSX(int &cycles);
    void LDA_ABSY(int &cycles);
    void LDA_INDX(int &cycles);
    void LDA_INDY(int &cycles);
};


/*Map Opcode*/
struct opcode {
    std::string name;
    unsigned char opcode;
    void (MOS6502::*operate)(int &cycles);
};

static opcode operations[] = {
        {"ADC_IM", 0x69, &MOS6502::ADC_IM},
        {"LDA_IM", 0xA9, &MOS6502::LDA_IM},
        {"LDA_ZERO", 0xA5, &MOS6502::LDA_ZERO},
        {"LDA_ZEROX", 0xB5, &MOS6502::LDA_ZEROX},
        {"LDA_ABS", 0xAD, &MOS6502::LDA_ABS},
        {"LDA_ABSX", 0xBD, &MOS6502::LDA_ABSX},
        {"LDA_ABSY", 0xB9, &MOS6502::LDA_ABSY},
        {"LDA_INDX", 0xA1, &MOS6502::LDA_INDX},
        {"LDA_INDY", 0xB1, &MOS6502::LDA_INDY},
};
