// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpPhantomBroadPhaseListener; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpBroadPhaseListener__VFTable;
struct hkpPhantomBroadPhaseListener__VFTable;
struct hkpPhantomBroadPhaseListener {
    hkpPhantomBroadPhaseListener__VFTable* vftable_hkpPhantomBroadPhaseListener_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpBroadPhaseListener__VFTable* vftable_hkpBroadPhaseListener_10;
};
static_assert(sizeof(hkpPhantomBroadPhaseListener) == 24, "hkpPhantomBroadPhaseListener layout differs from the PDB");
