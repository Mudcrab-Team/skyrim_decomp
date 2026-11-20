// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpWorldExtension; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpWorldExtension__VFTable;
struct hkpWorld_938ebb10;
struct hkpWorldExtension {
    hkpWorldExtension__VFTable* vftable_hkpWorldExtension_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpWorld_938ebb10* m_world_10;
    int m_id_18;
    unsigned short m_attachmentCount_1C;
    char _pad_1E[2];
};
static_assert(sizeof(hkpWorldExtension) == 32, "hkpWorldExtension layout differs from the PDB");
