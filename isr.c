#include <common.h>

const char *const isr_exceptions[] = {
	"Division By Zero",
	"Debug",
	"NMI",
	"Breakpoint",
	"Overflow",
	"Bound Range Exceeded",
	"Invalid Opcode",
	"Device Not Available",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Invalid TSS",
	"Segment Not Present",
	"Stack-Segment Fault",
	"General Protection Fault",
	"Page Fault",
	"Reserved",
	"x87 Floating-Point",
	"Alignment Check",
	"Machine Check",
	"SIMD Floating-Point",
	"Virtualization",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Security",
	"Reserved",
};

char *register_names[] = {
	"GS", "FS", "ES", "DS",
	"EDI", "ESI", "EBP", "ESP", "EBX", "EDX", "ECX", "EAX",
	"INT_NO", "ERR_CODE",
	"EIP", "CS", "EFLAGS", "USERESP", "SS",
};

// @TODO: Dump registers?
void isr_handler(Registers *regs) {
	if (regs->int_no < 32) {
		writef("%s Exception!\nDumping registers and halting.\n",
		       isr_exceptions[regs->int_no]);
		for (size_t i = 0; i < ARRAY_SIZE(register_names); ++i) {
			writef("%s: %x\n", register_names[i], *((int32_t *) regs + i));
		}
		hang();
	}
}
