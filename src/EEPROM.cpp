/*
 * Emmett
 */

#include <fstream>
#include "../include/emmett.h"

EEPROM::EEPROM()
{

}

void EEPROM::loadFile(std::string path)
{
    std::ifstream file(path);

    if (!file)
        std::cout << "File not found" << std::endl;
    while (file) {
        std::string line;
        std::getline(file, line);
        try {
            if (line.empty())
                continue;
            std::string address = line.substr(0, line.find(" "));
            std::string value = line.substr(line.find(" ") + 1, line.size());

            if (address == "START") {
                unsigned int v = std::stoi(value, nullptr, 16);
                _memory[0xFFFC]._value = v & 0xFF;
                _memory[0xFFFD]._value = (v >> 8) & 0xFF;
            } else
                _memory[std::stoi(address, nullptr, 16)]._value = std::stoi(value, nullptr, 16);
        } catch (std::exception &e) {
            std::cout << "invalid file: " << e.what() << std::endl;
        }
    }
}