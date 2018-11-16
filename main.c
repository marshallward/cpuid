#include <stdio.h>  // printf
#include "cpuid.h"

/* Test program for Cpuid class */

int main(int argc, char *argv[static 1])
{
    Cpuid *cpu = cpuid_create();

    printf("Max leafs: %i\n", cpu->max_leaf);
    printf("Vendor ID: %s\n", cpu->vendor_id);

    return 0;
}
