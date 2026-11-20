// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkGskCache16; size 0x10
#pragma once
struct hkGskCache16 {
    unsigned short m_vertices_0[4];
    unsigned char m_dimA_8;
    unsigned char m_dimB_9;
    unsigned char m_bitField_A_A;
    unsigned char m_gskFlags_B;
    char _pad_C[4];
};
static_assert(sizeof(hkGskCache16) == 16, "hkGskCache16 layout differs from the PDB");
