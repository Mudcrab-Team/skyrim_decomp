// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkLocalFrameGroup; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkStringPtr.h"
struct hkLocalFrameGroup__VFTable;
struct hkLocalFrameGroup {
    hkLocalFrameGroup__VFTable* vftable_hkLocalFrameGroup_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkStringPtr m_name_10;
};
static_assert(sizeof(hkLocalFrameGroup) == 24, "hkLocalFrameGroup layout differs from the PDB");
