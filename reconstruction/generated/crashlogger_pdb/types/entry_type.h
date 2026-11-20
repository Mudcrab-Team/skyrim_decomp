// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: entry_type; size 0x58
// one of 7 different PDB types sharing this name; the fullest
#pragma once
struct entry_type {
    unsigned char undefined_0[88];
};
static_assert(sizeof(entry_type) == 88, "entry_type layout differs from the PDB");
