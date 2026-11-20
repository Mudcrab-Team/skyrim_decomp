// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActionArray; size 0x18
#pragma once
struct ActionArray {
    unsigned char buffer_raw[8];
    unsigned int bufferSize;
    unsigned int effectiveSize;
    unsigned int count;
    unsigned int pad14;
};
static_assert(sizeof(ActionArray) == 24, "ActionArray layout differs from the PDB");
