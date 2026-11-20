// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Target; size 0x8
#pragma once
struct Target {
    unsigned char interruptTarg_raw[8];
};
static_assert(sizeof(Target) == 8, "Target layout differs from the PDB");
