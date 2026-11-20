// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FILETIME; size 0x8
#pragma once
struct FILETIME {
    unsigned int lo;
    unsigned int hi;
};
static_assert(sizeof(FILETIME) == 8, "FILETIME layout differs from the PDB");
