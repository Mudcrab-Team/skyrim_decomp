// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTScatterTableStandardParent; size 0x18
#pragma once
struct BSTScatterTableStandardParent {
    unsigned long long _pad00;
    unsigned int _pad08;
    unsigned int _capacity;
    unsigned int _free;
    unsigned int _good;
};
static_assert(sizeof(BSTScatterTableStandardParent) == 24, "BSTScatterTableStandardParent layout differs from the PDB");
