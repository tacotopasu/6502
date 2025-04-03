#include <iostream>
#include "cpu.h"

void unknown_opcode(uint8_t opcode)
{
    std::cerr << "Opcode unknown or not implemented: " << std::hex << static_cast<int>(opcode) << std::endl;
} 

void execute_lda_imm(CPU& cpu)
{
    // Loading the immediate value from memory into the accumulator and incrementing the program counter
    cpu.a = cpu.memory[cpu.pc++];

    // Setting the CPU flags
    cpu.status =    (cpu.status     & ~(0x80 | 0x02))   |   // Clear Negative and Zero Flags
                    ((cpu.a == 0)   ? 0x02 : 0x00)      |   // Setting Zero Flag if Accumulator is Zero
                    ((cpu.a & 0x80) ? 0x80 : 0x00);         // Setting Negative Flag if Accumulator is Negative (bit 7 is set)
}

u_int8_t fetch(CPU& cpu)
{
    return cpu.memory[cpu.pc++];
}

void decode(u_int8_t opcode, CPU& cpu)
{
    switch(opcode)
    {
        case LDA_IMM:
            execute_lda_imm(cpu);
            break;
        default:
            unknown_opcode(opcode);
            break;
    }
}