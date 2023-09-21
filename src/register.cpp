/*
 * Emmett
 */

#include "../include/emmett.h"

Register::Register()
{
    _value = 0;
};

void Register::set(unsigned char value)
{
    _value = value;
};
