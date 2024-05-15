/*
 * Emmett
 */

#include "../include/emmett.h"

int main(int argc, char **argv)
{
    int cycles = -1;
    std::string fileName = "file.txt";
    MOS6502 cpu;
    EEPROM eeprom;

    if (unitTests())
        return 0;

    if (argc == 2) {
        fileName = argv[1];
    } else
        for (int i = 1; i < argc; i++) {
            if (std::string(argv[i]).find("-c") != std::string::npos) {
                if (std::string(argv[i + 1]).find("-") != std::string::npos) {
                    std::cerr << "Usage: ./emmett <filename:=file.txt> || ./emmett -c <cycle number:=-1> -f <filename:=file.txt> -t (for debug printing)" << std::endl;
                    return 84;
                }
                if (i + 1 >= argc) {
                    std::cerr << "Usage: ./emmett <filename:=file.txt> || ./emmett -c <cycle number:=-1> -f <filename:=file.txt> -t (for debug printing)" << std::endl;
                    return 84;
                }
                cycles = std::stoi(argv[i + 1]);
                i++;
            }
            if (std::string(argv[i]).find("-f") != std::string::npos) {
                if (std::string(argv[i + 1]).find("-") != std::string::npos) {
                    std::cerr << "Usage: ./emmett <filename:=file.txt> || ./emmett -c <cycle number:=-1> -f <filename:=file.txt> -t (for debug printing)" << std::endl;
                    return 84;
                }
                if (i + 1 >= argc) {
                    std::cerr << "Usage: ./emmett <filename:=file.txt> || ./emmett -c <cycle number:=-1> -f <filename:=file.txt> -t (for debug printing)" << std::endl;
                    return 84;
                }
                fileName = argv[i + 1];
                i++;
            }
            if (std::string(argv[i]).find("-h") != std::string::npos) {
                std::cout << "Usage: ./emmett <file> [-c <cycles>] [-f <file>] [-h]" << std::endl;
                return 0;
            }
            if (std::string(argv[i]).find("-t") != std::string::npos) {
                cpu._debugPrint = true;
            }
        }

    if (fileName.empty()) {
        std::cerr << "Usage: ./emmett <filename:=file.txt> || ./emmett -c <cycle number:=-1> -f <filename:=file.txt> -t (for debug printing)" << std::endl;
        return 84;
    }

    eeprom.loadFile(fileName);
    for (int i = 0; i < 0x10000; i++)
        cpu._memory[i] = eeprom._memory[i];

    cpu.reset();
    cpu.execute(cycles);
    return 0;
}