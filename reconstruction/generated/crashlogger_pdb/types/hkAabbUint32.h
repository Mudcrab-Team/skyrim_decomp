// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkAabbUint32; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkAabbUint32 {
    unsigned int m_min_0[3];
    unsigned char m_expansionMin_C[3];
    unsigned char m_expansionShift_F;
    unsigned int m_max_10[3];
    unsigned char m_expansionMax_1C[3];
    unsigned char m_shapeKeyByte_1F;
};
static_assert(sizeof(hkAabbUint32) == 32, "hkAabbUint32 layout differs from the PDB");
