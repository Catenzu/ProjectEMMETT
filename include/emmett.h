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
    void setMemory(uint16_t address, unsigned char value, int &cycles);

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

    /*Get Bytes Adressing Modes*/
    unsigned char getValueImmediate(int &cycles);
    unsigned char getValueZeroPage(int &cycles);
    unsigned char getValueZeroPageX(int &cycles);
    unsigned char getValueZeroPageY(int &cycles);
    unsigned char getValueAbsolute(int &cycles);
    unsigned char getValueAbsoluteX(int &cycles);
    unsigned char getValueAbsoluteY(int &cycles);
    unsigned char getValueIndirectX(int &cycles);
    unsigned char getValueIndirectY(int &cycles);

    /*Opcode*/
    void ADC_IM(int &cycles);
    void ADC_ZERO(int &cycles);
    void ADC_ZEROX(int &cycles);
    void ADC_ABS(int &cycles);
    void ADC_ABSX(int &cycles);
    void ADC_ABSY(int &cycles);
    void ADC_INDX(int &cycles);
    void ADC_INDY(int &cycles);
  
    void AND_IM(int &cycles);
    void AND_ZERO(int &cycles);
    void AND_ZEROX(int &cycles);
    void AND_ABS(int &cycles);
    void AND_ABSX(int &cycles);
    void AND_ABSY(int &cycles);
    void AND_INDX(int &cycles);
    void AND_INDY(int &cycles);

    void ASL_ACC(int &cycles);
    void ASL_ZERO(int &cycles);
    void ASL_ZEROX(int &cycles);
    void ASL_ABS(int &cycles);
    void ASL_ABSX(int &cycles);
  
    void LDA_IM(int &cycles);
    void LDA_ZERO(int &cycles);
    void LDA_ZEROX(int &cycles);
    void LDA_ABS(int &cycles);
    void LDA_ABSX(int &cycles);
    void LDA_ABSY(int &cycles);
    void LDA_INDX(int &cycles);
    void LDA_INDY(int &cycles);

    void LDX_IM(int &cycles);
    void LDX_ZERO(int &cycles);
    void LDX_ZEROY(int &cycles);
    void LDX_ABS(int &cycles);
    void LDX_ABSY(int &cycles);

    void LDY_IM(int &cycles);
    void LDY_ZERO(int &cycles);
    void LDY_ZEROX(int &cycles);
    void LDY_ABS(int &cycles);
    void LDY_ABSX(int &cycles);

    void STA_ZERO(int &cycles);
    void STA_ZEROX(int &cycles);
    void STA_ABS(int &cycles);
    void STA_ABSX(int &cycles);
    void STA_ABSY(int &cycles);
    void STA_INDX(int &cycles);
    void STA_INDY(int &cycles);

    void STX_ZERO(int &cycles);
    void STX_ZEROY(int &cycles);
    void STX_ABS(int &cycles);

    void STY_ZERO(int &cycles);
    void STY_ZEROX(int &cycles);
    void STY_ABS(int &cycles);

    void TAX(int &cycles);
    void TAY(int &cycles);
    void TXA(int &cycles);
    void TYA(int &cycles);
    void TSX(int &cycles);
    void TXS(int &cycles);

    void PHA(int &cycles);
    void PHP(int &cycles);
    void PLA(int &cycles);
    void PLP(int &cycles);

    void JMP_ABS(int &cycles);
    void JMP_IND(int &cycles);
    void JSR_ABS(int &cycles);
    void RTS(int &cycles);
};


/*Map Opcode*/
struct opcode {
    std::string name;
    unsigned char opcode;
    void (MOS6502::*operate)(int &cycles);
};

static opcode operations[] = {
        {"ADC_IM", 0x69, &MOS6502::ADC_IM},
        {"ADC_ZERO", 0x65, &MOS6502::ADC_ZERO},
        {"ADC_ZEROX", 0x75, &MOS6502::ADC_ZEROX},
        {"ADC_ABS", 0x6D, &MOS6502::ADC_ABS},
        {"ADC_ABSX", 0x7D, &MOS6502::ADC_ABSX},
        {"ADC_ABSY", 0x79, &MOS6502::ADC_ABSY},
        {"ADC_INDX", 0x61, &MOS6502::ADC_INDX},
        {"ADC_INDY", 0x71, &MOS6502::ADC_INDY},
        {"AND_IM", 0x29, &MOS6502::AND_IM},
        {"AND_ZERO", 0x25, &MOS6502::AND_ZERO},
        {"AND_ZEROX", 0x35, &MOS6502::AND_ZEROX},
        {"AND_ABS", 0x2D, &MOS6502::AND_ABS},
        {"AND_ABSX", 0x3D, &MOS6502::AND_ABSX},
        {"AND_ABSY", 0x39, &MOS6502::AND_ABSY},
        {"AND_INDX", 0x21, &MOS6502::AND_INDX},
        {"AND_INDY", 0x31, &MOS6502::AND_INDY},
        {"ASL_ACC", 0x0A, &MOS6502::ASL_ACC},
        {"ASL_ZERO", 0x06, &MOS6502::ASL_ZERO},
        {"ASL_ZEROX", 0x16, &MOS6502::ASL_ZEROX},
        {"ASL_ABS", 0x0E, &MOS6502::ASL_ABS},
        {"ASL_ABSX", 0x1E, &MOS6502::ASL_ABSX},
        {"LDA_IM", 0xA9, &MOS6502::LDA_IM},
        {"LDA_ZERO", 0xA5, &MOS6502::LDA_ZERO},
        {"LDA_ZEROX", 0xB5, &MOS6502::LDA_ZEROX},
        {"LDA_ABS", 0xAD, &MOS6502::LDA_ABS},
        {"LDA_ABSX", 0xBD, &MOS6502::LDA_ABSX},
        {"LDA_ABSY", 0xB9, &MOS6502::LDA_ABSY},
        {"LDA_INDX", 0xA1, &MOS6502::LDA_INDX},
        {"LDA_INDY", 0xB1, &MOS6502::LDA_INDY},
        {"LDX_IM", 0xA2, &MOS6502::LDX_IM},
        {"LDX_ZERO", 0xA6, &MOS6502::LDX_ZERO},
        {"LDX_ZEROY", 0xB6, &MOS6502::LDX_ZEROY},
        {"LDX_ABS", 0xAE, &MOS6502::LDX_ABS},
        {"LDX_ABSY", 0xBE, &MOS6502::LDX_ABSY},
        {"LDY_IM", 0xA0, &MOS6502::LDY_IM},
        {"LDY_ZERO", 0xA4, &MOS6502::LDY_ZERO},
        {"LDY_ZEROX", 0xB4, &MOS6502::LDY_ZEROX},
        {"LDY_ABS", 0xAC, &MOS6502::LDY_ABS},
        {"LDY_ABSX", 0xBC, &MOS6502::LDY_ABSX},
        {"STA_ZERO", 0x85, &MOS6502::STA_ZERO},
        {"STA_ZEROX", 0x95, &MOS6502::STA_ZEROX},
        {"STA_ABS", 0x8D, &MOS6502::STA_ABS},
        {"STA_ABSX", 0x9D, &MOS6502::STA_ABSX},
        {"STA_ABSY", 0x99, &MOS6502::STA_ABSY},
        {"STA_INDX", 0x81, &MOS6502::STA_INDX},
        {"STA_INDY", 0x91, &MOS6502::STA_INDY},
        {"STX_ZERO", 0x86, &MOS6502::STX_ZERO},
        {"STX_ZEROY", 0x96, &MOS6502::STX_ZEROY},
        {"STX_ABS", 0x8E, &MOS6502::STX_ABS},
        {"STY_ZERO", 0x84, &MOS6502::STY_ZERO},
        {"STY_ZEROX", 0x94, &MOS6502::STY_ZEROX},
        {"STY_ABS", 0x8C, &MOS6502::STY_ABS},
        {"TAX", 0xAA, &MOS6502::TAX},
        {"TAY", 0xA8, &MOS6502::TAY},
        {"TXA", 0x8A, &MOS6502::TXA},
        {"TYA", 0x98, &MOS6502::TYA},
        {"TSX", 0xBA, &MOS6502::TSX},
        {"TXS", 0x9A, &MOS6502::TXS},
        {"PHA", 0x48, &MOS6502::PHA},
        {"PHP", 0x08, &MOS6502::PHP},
        {"PLA", 0x68, &MOS6502::PLA},
        {"PLP", 0x28, &MOS6502::PLP},
        {"JMP_ABS", 0x4C, &MOS6502::JMP_ABS},
        {"JMP_IND", 0x6C, &MOS6502::JMP_IND},
        {"JSR_ABS", 0x20, &MOS6502::JSR_ABS},
        {"RTS", 0x60, &MOS6502::RTS},
};
