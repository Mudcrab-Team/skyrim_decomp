// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkHalf; size 0x2
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkHalf {
    short m_value_0;
};
static_assert(sizeof(hkHalf) == 2, "hkHalf layout differs from the PDB");
