// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpGskCache; size 0xc
#pragma once
struct hkpGskCache {
    unsigned short m_vertices_0[4];
    unsigned char m_dimA_8;
    unsigned char m_dimB_9;
    unsigned char m_bitField_A_A;
    unsigned char m_gskFlags_B;
};
static_assert(sizeof(hkpGskCache) == 12, "hkpGskCache layout differs from the PDB");
