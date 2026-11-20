// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkKdTreeProjectedEntry; size 0x20
#pragma once
struct hkKdTreeProjectedEntry {
    unsigned short m_min_0[3];
    char _pad_6[2];
    unsigned int m_primIdHigh_8;
    unsigned short m_max_C[3];
    char _pad_12[2];
    unsigned int m_primIdLow_14;
    char _pad_18[8];
};
static_assert(sizeof(hkKdTreeProjectedEntry) == 32, "hkKdTreeProjectedEntry layout differs from the PDB");
