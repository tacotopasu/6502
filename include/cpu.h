#include <map>
#include <cstdint>

struct CPU {                // - Represents the 6502 CPU state
    uint16_t pc;           // Program Counter
    uint8_t a;             // Accumulator
    uint8_t x;             // X Register
    uint8_t y;             // Y Register
    uint8_t sp;            // Stack Pointer
    uint8_t status;        // Status Register (flags)
    uint8_t memory[65536]; // 64KB of memory
};

enum Opcodes {              // - Opcodes for the 6502 CPU
    LDA_IMM = 0xA9,         // Load Accumulator Immediate
    LDX_IMM = 0xA2,         // Load X Register Immediate
    LDY_IMM = 0xA0,         // Load Y Register Immediate
    STA_ABS = 0x8D,         // Store Accumulator Absolute
    STX_ABS = 0x8E,         // Store X Register Absolute
    STY_ABS = 0x8C,         // Store Y Register Absolute
    ADC_IMM = 0x69,         // Add with Carry Immediate
    SBC_IMM = 0xE9,         // Subtract with Carry Immediate
    JMP_ABS = 0x4C,         // Jump Absolute
    JSR_ABS = 0x20,         // Jump to Subroutine Absolute
    RTS = 0x60,             // Return from Subroutine
    NOP = 0xEA              // No Operation
};

void unknown_opcode(uint8_t opcode);

void execute_lda_imm(CPU& cpu);

void decode(uint8_t opcode, CPU& cpu);
uint8_t fetch(CPU& cpu);
