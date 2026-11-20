// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTScatterTableFixedParent; size 0x10
#pragma once
struct BSTScatterTableFixedParent {
    unsigned int _pad00;
    unsigned int _free;
    unsigned int _good;
    unsigned int _capacity;
};
static_assert(sizeof(BSTScatterTableFixedParent) == 16, "BSTScatterTableFixedParent layout differs from the PDB");
