// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpNullBroadPhaseListener; size 0x18
#pragma once

struct hkpBroadPhaseListener__VFTable;
struct hkpNullBroadPhaseListener__VFTable;
struct hkpNullBroadPhaseListener {
    hkpNullBroadPhaseListener__VFTable* vftable_hkpNullBroadPhaseListener_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpBroadPhaseListener__VFTable* vftable_hkpBroadPhaseListener_10;
};
static_assert(sizeof(hkpNullBroadPhaseListener) == 24, "hkpNullBroadPhaseListener layout differs from the PDB");
