// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: _FILETIME; size 0x8
#pragma once
struct FILETIME_7813ec6f {
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
};
static_assert(sizeof(FILETIME_7813ec6f) == 8, "FILETIME_7813ec6f layout differs from the PDB");
