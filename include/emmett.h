/*
 * Emmett
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>

class Register {
public:
    Register();

    void set(unsigned char value);

    unsigned char _value;
};

class MOS6502 {
public:
    MOS6502();

    void reset();
    void execute(int cycles);
    unsigned char fetch(int &cycles);

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
};
