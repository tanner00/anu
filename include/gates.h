#pragma once

// https://wiki.osdev.org/Descriptor

#define DATA_SELECTOR 0x08

#define DESCRIPTOR_PRESENT 0b10000000
#define DPL_KERNEL 0b00000000
#define DPL_USER 0b01100000
#define INT_TRAP_STORAGE_SEGMENT 0b00000000
#define TASK_STORAGE_SEGMENT 0b00001000

// @NOTE: there are 16-bit gates too
#define TASK_GATE_32BIT 0b00000101
#define INT_GATE_32BIT 0b00001110
#define TRAP_GATE_32BIT 0b00001111

#define INT_GATE_FLAGS                                                         \
	DESCRIPTOR_PRESENT | DPL_KERNEL | INT_TRAP_STORAGE_SEGMENT |           \
		INT_GATE_32BIT
