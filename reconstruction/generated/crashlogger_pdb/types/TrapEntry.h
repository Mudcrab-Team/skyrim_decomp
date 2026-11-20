// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TrapEntry; size 0x30
#pragma once
struct TrapEntry {
    unsigned char undefined_0[48];
};
static_assert(sizeof(TrapEntry) == 48, "TrapEntry layout differs from the PDB");
