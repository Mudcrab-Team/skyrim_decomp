// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkStringPtr; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkStringPtr {
    char* m_stringAndFlag_0;
};
static_assert(sizeof(hkStringPtr) == 8, "hkStringPtr layout differs from the PDB");
