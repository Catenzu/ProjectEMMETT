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

    /*Register*/
    Register a;
    Register x;
    Register y;
    Register sp;
    Register sr;
    uint16_t pc;

    /*Memory*/
    void setMemory(uint16_t address, unsigned char value);
    Register memory[65536];
};
