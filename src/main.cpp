#include "cpu.cpp"

int main() {
    CPU cpu;
    cpu.pc = 0x0200;                // Set initial program counter value

    // Load program into memory (example)
    cpu.memory[0x0200] = LDA_IMM;   // LDA #$20
    cpu.memory[0x0201] = 0x20;      // Immediate value $20

    // Emulation loop
    for (int i = 0; i < 1; ++i)         // Execute one instruction for demonstration
    {       
        u_int8_t opcode = fetch(cpu);
        decode(opcode, cpu);
    }

    // Print CPU state after execution
    printf("Accumulator:     0x%02X\n", cpu.a);
    printf("Program Counter: 0x%04X\n", cpu.pc);
    printf("Status Register: 0x%02X\n", cpu.status);

    return 0;
}