/*
 * Emmett
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <bitset>

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
    void setZeroFlagFromByte(unsigned char value);
    void setNegativeFlagFromByte(unsigned char value);
    void setZeroFlag(bool value);
    void setNegativeFlag(bool value);
    void setCarryFlag(bool value);
    void setOverflowFlag(bool value);

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

    uint16_t getAdressZeroPage(int &cycles);
    uint16_t getAdressZeroPageX(int &cycles);
    uint16_t getAdressZeroPageY(int &cycles);
    uint16_t getAdressAbsolute(int &cycles);
    uint16_t getAdressAbsoluteX(int &cycles);
    uint16_t getAdressAbsoluteY(int &cycles);
    uint16_t getAdressIndirectX(int &cycles);
    uint16_t getAdressIndirectY(int &cycles);

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

    void EOR_IM(int &cycles);
    void EOR_ZERO(int &cycles);
    void EOR_ZEROX(int &cycles);
    void EOR_ABS(int &cycles);
    void EOR_ABSX(int &cycles);
    void EOR_ABSY(int &cycles);
    void EOR_INDX(int &cycles);
    void EOR_INDY(int &cycles);

    void ORA_IM(int &cycles);
    void ORA_ZERO(int &cycles);
    void ORA_ZEROX(int &cycles);
    void ORA_ABS(int &cycles);
    void ORA_ABSX(int &cycles);
    void ORA_ABSY(int &cycles);
    void ORA_INDX(int &cycles);
    void ORA_INDY(int &cycles);

    void ASL_ACC(int &cycles);
    void ASL_ZERO(int &cycles);
    void ASL_ZEROX(int &cycles);
    void ASL_ABS(int &cycles);
    void ASL_ABSX(int &cycles);

    void BCC(int &cycles);
    void BCS(int &cycles);
    void BEQ(int &cycles);
    void BMI(int &cycles);
    void BNE(int &cycles);
    void BPL(int &cycles);
    void BVC(int &cycles);
    void BVS(int &cycles);

    void CMP_IM(int &cycles);
    void CMP_ZERO(int &cycles);
    void CMP_ZEROX(int &cycles);
    void CMP_ABS(int &cycles);
    void CMP_ABSX(int &cycles);
    void CMP_ABSY(int &cycles);
    void CMP_INDX(int &cycles);
    void CMP_INDY(int &cycles);

    void CPX_IM(int &cycles);
    void CPX_ZERO(int &cycles);
    void CPX_ABS(int &cycles);

    void CPY_IM(int &cycles);
    void CPY_ZERO(int &cycles);
    void CPY_ABS(int &cycles);

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

    void ROL_ACC(int &cycles);
    void ROL_ZERO(int &cycles);
    void ROL_ZEROX(int &cycles);
    void ROL_ABS(int &cycles);
    void ROL_ABSX(int &cycles);

    void ROR_ACC(int &cycles);
    void ROR_ZERO(int &cycles);
    void ROR_ZEROX(int &cycles);
    void ROR_ABS(int &cycles);
    void ROR_ABSX(int &cycles);

    void SBC_IM(int &cycles);
    void SBC_ZERO(int &cycles);
    void SBC_ZEROX(int &cycles);
    void SBC_ABS(int &cycles);
    void SBC_ABSX(int &cycles);
    void SBC_ABSY(int &cycles);
    void SBC_INDX(int &cycles);
    void SBC_INDY(int &cycles);

    void CLC(int &cycles);
    void SEC(int &cycles);
    void CLI(int &cycles);
    void SEI(int &cycles);
    void CLV(int &cycles);
    void CLD(int &cycles);
    void SED(int &cycles);

    void NOP(int &cycles);

    void BIT_ZERO(int &cycles);
    void BIT_ABS(int &cycles);

    void DEC_ZERO(int &cycles);
    void DEC_ZEROX(int &cycles);
    void DEC_ABS(int &cycles);
    void DEC_ABSX(int &cycles);
    void DEX(int &cycles);
    void DEY(int &cycles);
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
        {"EOR_IM", 0x49, &MOS6502::EOR_IM},
        {"EOR_ZERO", 0x45, &MOS6502::EOR_ZERO},
        {"EOR_ZEROX", 0x55, &MOS6502::EOR_ZEROX},
        {"EOR_ABS", 0x4D, &MOS6502::EOR_ABS},
        {"EOR_ABSX", 0x5D, &MOS6502::EOR_ABSX},
        {"EOR_ABSY", 0x59, &MOS6502::EOR_ABSY},
        {"EOR_INDX", 0x41, &MOS6502::EOR_INDX},
        {"EOR_INDY", 0x51, &MOS6502::EOR_INDY},
        {"ORA_IM", 0x09, &MOS6502::ORA_IM},
        {"ORA_ZERO", 0x05, &MOS6502::ORA_ZERO},
        {"ORA_ZEROX", 0x15, &MOS6502::ORA_ZEROX},
        {"ORA_ABS", 0x0D, &MOS6502::ORA_ABS},
        {"ORA_ABSX", 0x1D, &MOS6502::ORA_ABSX},
        {"ORA_ABSY", 0x19, &MOS6502::ORA_ABSY},
        {"ORA_INDX", 0x01, &MOS6502::ORA_INDX},
        {"ORA_INDY", 0x11, &MOS6502::ORA_INDY},
        {"ASL_ACC", 0x0A, &MOS6502::ASL_ACC},
        {"ASL_ZERO", 0x06, &MOS6502::ASL_ZERO},
        {"ASL_ZEROX", 0x16, &MOS6502::ASL_ZEROX},
        {"ASL_ABS", 0x0E, &MOS6502::ASL_ABS},
        {"ASL_ABSX", 0x1E, &MOS6502::ASL_ABSX},
        {"BIT_ZERO", 0x24, &MOS6502::BIT_ZERO},
        {"BIT_ABS", 0x2C, &MOS6502::BIT_ABS},
        {"BCC", 0x90, &MOS6502::BCC},
        {"BCS", 0xB0, &MOS6502::BCS},
        {"BEQ", 0xF0, &MOS6502::BEQ},
        {"BMI", 0x30, &MOS6502::BMI},
        {"BNE", 0xD0, &MOS6502::BNE},
        {"BPL", 0x10, &MOS6502::BPL},
        {"BVC", 0x50, &MOS6502::BVC},
        {"BVS", 0x70, &MOS6502::BVS},
        {"CMP_IM", 0xC9, &MOS6502::CMP_IM},
        {"CMP_ZERO", 0xC5, &MOS6502::CMP_ZERO},
        {"CMP_ZEROX", 0xD5, &MOS6502::CMP_ZEROX},
        {"CMP_ABS", 0xCD, &MOS6502::CMP_ABS},
        {"CMP_ABSX", 0xDD, &MOS6502::CMP_ABSX},
        {"CMP_ABSY", 0xD9, &MOS6502::CMP_ABSY},
        {"CMP_INDX", 0xC1, &MOS6502::CMP_INDX},
        {"CMP_INDY", 0xD1, &MOS6502::CMP_INDY},
        {"CPX_IM", 0xE0, &MOS6502::CPX_IM},
        {"CPX_ZERO", 0xE4, &MOS6502::CPX_ZERO},
        {"CPX_ABS", 0xEC, &MOS6502::CPX_ABS},
        {"CPY_IM", 0xC0, &MOS6502::CPY_IM},
        {"CPY_ZERO", 0xC4, &MOS6502::CPY_ZERO},
        {"CPY_ABS", 0xCC, &MOS6502::CPY_ABS},
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
        {"ROL_ACC", 0x2A, &MOS6502::ROL_ACC},
        {"ROL_ZERO", 0x26, &MOS6502::ROL_ZERO},
        {"ROL_ZEROX", 0x36, &MOS6502::ROL_ZEROX},
        {"ROL_ABS", 0x2E, &MOS6502::ROL_ABS},
        {"ROL_ABSX", 0x3E, &MOS6502::ROL_ABSX},
        {"ROR_ACC", 0x6A, &MOS6502::ROR_ACC},
        {"ROR_ZERO", 0x66, &MOS6502::ROR_ZERO},
        {"ROR_ZEROX", 0x76, &MOS6502::ROR_ZEROX},
        {"ROR_ABS", 0x6E, &MOS6502::ROR_ABS},
        {"ROR_ABSX", 0x7E, &MOS6502::ROR_ABSX},
        {"SBC_IM", 0xE9, &MOS6502::SBC_IM},
        {"SBC_ZERO", 0xE5, &MOS6502::SBC_ZERO},
        {"SBC_ZEROX", 0xF5, &MOS6502::SBC_ZEROX},
        {"SBC_ABS", 0xED, &MOS6502::SBC_ABS},
        {"SBC_ABSX", 0xFD, &MOS6502::SBC_ABSX},
        {"SBC_ABSY", 0xF9, &MOS6502::SBC_ABSY},
        {"SBC_INDX", 0xE1, &MOS6502::SBC_INDX},
        {"SBC_INDY", 0xF1, &MOS6502::SBC_INDY},
        {"CLC", 0x18, &MOS6502::CLC},
        {"SEC", 0x38, &MOS6502::SEC},
        {"CLI", 0x58, &MOS6502::CLI},
        {"SEI", 0x78, &MOS6502::SEI},
        {"CLV", 0xB8, &MOS6502::CLV},
        {"CLD", 0xD8, &MOS6502::CLD},
        {"SED", 0xF8, &MOS6502::SED},
        {"NOP", 0xEA, &MOS6502::NOP},
        {"DEC_ZERO", 0xC6, &MOS6502::DEC_ZERO},
        {"DEC_ZEROX", 0xD6, &MOS6502::DEC_ZEROX},
        {"DEC_ABS", 0xCE, &MOS6502::DEC_ABS},
        {"DEC_ABSX", 0xDE, &MOS6502::DEC_ABSX},
        {"DEX", 0xCA, &MOS6502::DEX},
        {"DEY", 0x88, &MOS6502::DEY},
};
