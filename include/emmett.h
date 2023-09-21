/*
 * Emmett
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>

class MOS6502 {
public:
    MOS6502();
};

class Register {
public:
    Register();

    void set(char value);
    void set(std::string sValue);

    unsigned char _value;
};

