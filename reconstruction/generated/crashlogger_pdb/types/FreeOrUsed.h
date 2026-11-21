// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FreeOrUsed; size 0x8
#pragma once
struct FreeOrUsed {
    unsigned char used_raw[8];
};
static_assert(sizeof(FreeOrUsed) == 8, "FreeOrUsed layout differs from the PDB");
