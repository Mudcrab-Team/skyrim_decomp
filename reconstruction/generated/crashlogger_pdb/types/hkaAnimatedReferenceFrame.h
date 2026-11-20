// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaAnimatedReferenceFrame; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkReferencedObject__VFTable;
struct hkaAnimatedReferenceFrame {
    hkReferencedObject__VFTable* vftable_hkReferencedObject_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
};
static_assert(sizeof(hkaAnimatedReferenceFrame) == 16, "hkaAnimatedReferenceFrame layout differs from the PDB");
