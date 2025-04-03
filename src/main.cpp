#include "cpu.cpp"

int main() {
    CPU cpu;
    cpu.pc = 0x0200; // Set initial program counter value
    // Load program into memory (example)
    cpu.memory[0x0200] = LDA_IMM;   // LDA #$20
    cpu.memory[0x0201] = 0x20;      // Immediate value $20

    // Emulation loop
    for (int i = 0; i < 1; ++i) {       // Execute one instruction for demonstration
        u_int8_t opcode = fetch(cpu);   // Fetch the opcode
        decode(opcode, cpu);            // Decode the opcode
    }

    // Print the final state of the CPU (for debugging)
    printf("Accumulator:     0x%02X\n", cpu.a);         // Print accumulator value
    printf("Program Counter: 0x%04X\n", cpu.pc);        // Print program counter value
    printf("Status Register: 0x%02X\n", cpu.status);    // Print status register value

    return 0;
}