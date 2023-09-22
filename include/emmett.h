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
    void execute(int cycles);
    unsigned char fetch(int &cycles);
    unsigned char fetchX(int &cycles);
    unsigned char fetchY(int &cycles);
    unsigned char getMemory(uint16_t address, int &cycles);

    /*Register*/
    Register a; //Accumulator
    Register x;
    Register y;
    Register sp; //Stack Pointer
    Register sr; //Status Register
    uint16_t pc; //Program Counter

    /*Memory*/
    void setMemory(uint16_t address, unsigned char value);
    Register memory[65536];

    /*Opcode*/
    void LDA_IM(int &cycles);
    void LDA_ZERO(int &cycles);
    void LDA_ZEROX(int &cycles);
};


/*Map Opcode*/
struct opcode {
    std::string name;
    unsigned char opcode;
    void (MOS6502::*operate)(int &cycles);
};

static opcode operations[] = {
        {"LDA_IM", 0xA9, &MOS6502::LDA_IM},
        {"LDA_ZERO", 0xA5, &MOS6502::LDA_ZERO},
        {"LDA_ZEROX", 0xB5, &MOS6502::LDA_ZEROX},
};
