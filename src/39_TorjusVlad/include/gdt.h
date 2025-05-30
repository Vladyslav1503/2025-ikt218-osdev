#ifndef GDT
#define GDT

#include "libc/stdint.h"

struct gdt_entry {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
    } __attribute__((packed));

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
    } __attribute__((packed));

void init_gdt();
void set_gdt_gate(uint32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);

#endif