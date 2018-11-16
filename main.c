#include <stdio.h>  // printf
#include "cpuid.h"

/* Test program for Cpuid class */

int main(int argc, char *argv[static 1])
{
    Cpuid *cpu = cpuid_create();

    printf("Max leaf: 0x%x\n", cpu->max_leaf);
    printf("Max subleaf: 0x%x\n", cpu->max_subleaf);
    printf("Vendor ID: %s\n", cpu->vendor_id);

    return 0;
}
