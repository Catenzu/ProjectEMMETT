/*
 * Emmett
 */

#include "../include/emmett.h"

int main()
{
    Register a;
    a.set("0xFF");
    std::cout << (int) a._value << std::endl;
    a.set("00001010");
    std::cout << (int) a._value << std::endl;
    a.set("11111111");
    std::cout << (int) a._value << std::endl;
    return 0;
}