#ifndef CPUID_H_
#define CPUID_H_

typedef struct Cpuid_struct {
    int max_leaf;           // Maximum valid leaf value
    char vendor_id[13];     // Vendor ID string
} Cpuid;

Cpuid * cpuid_create(void);

#endif //CPUID_H_
