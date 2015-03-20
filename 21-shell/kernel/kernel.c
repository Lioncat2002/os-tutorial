#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"

void main() {
    isr_install();
    irq_install();

    kprint("Type something, it will go through the kernel\n"
        "Type END to halt the CPU\n> ");

    // Do we need an infinite loop here?
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }
    kprint("You said: ");
    kprint(input);
    kprint("\n> ");
}
