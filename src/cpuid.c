#include <stdint.h> // uint32_t
#include <stdlib.h> // malloc
#include "cpuid.h"

#include <stdio.h>

void get_vendor_id(char *);


// Internal struct to read CPUID output
struct cpu_regs {
    uint32_t eax;   // Accumulator
    uint32_t ebx;   // Base
    uint32_t ecx;   // Counter
    uint32_t edx;   // Data
};


struct cpu_regs call_cpuid(int leaf, int subleaf) {
    struct cpu_regs reg = {};

    asm volatile (
        "cpuid\n"
        :
        "=a" (reg.eax),
        "=b" (reg.ebx),
        "=c" (reg.ecx),
        "=d" (reg.edx)
        :
        "a" (leaf),
        "c" (subleaf)
    );

    return reg;
}


Cpuid * cpuid_create() {
    Cpuid *cpu;
    cpu = malloc(sizeof(Cpuid));

    // Set the maxium valid leaf value
    cpu->max_leaf = call_cpuid(0, 0).eax;
    get_vendor_id(cpu->vendor_id);

    return cpu;
}


void get_vendor_id(char *vendor_id) {
    struct cpu_regs reg = call_cpuid(0, 0);

    // Vendor string is EBX + EDX + ECX
    for(int i = 0; i < 4; i++) {
        vendor_id[i] = ((char *) &(reg.ebx))[i];
        vendor_id[i + 4] = ((char *) &(reg.edx))[i];
        vendor_id[i + 8] = ((char *) &(reg.ecx))[i];
    }
    vendor_id[12] = '\0';
}
