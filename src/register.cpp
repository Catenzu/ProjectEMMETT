/*
 * Emmett
 */

#include "../include/emmett.h"

Register::Register()
{
    _value = 0;
};

void Register::set(char value)
{
    _value = value;
};

void Register::set(std::string sValue)
{
    if (sValue.length() == 4) { //Hexadecimal : a.set("0xFF");
        auto value = (unsigned char) std::stoi(sValue, nullptr, 16);
        set(value);
    } else if (sValue.length() == 8) { //Binary : a.set("00001010");
        auto value = (unsigned char) std::stoi(sValue, nullptr, 2);
        set(value);
    } else
        std::cerr << "Invalid value for register" << std::endl;
}
