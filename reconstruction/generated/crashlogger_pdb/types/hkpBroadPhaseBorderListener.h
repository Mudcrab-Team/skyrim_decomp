// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBroadPhaseBorderListener; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpBroadPhaseBorderListener__VFTable;
struct hkpBroadPhaseListener__VFTable;
struct hkpBroadPhaseBorderListener {
    hkpBroadPhaseBorderListener__VFTable* vftable_hkpBroadPhaseBorderListener_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpBroadPhaseListener__VFTable* vftable_hkpBroadPhaseListener_10;
};
static_assert(sizeof(hkpBroadPhaseBorderListener) == 24, "hkpBroadPhaseBorderListener layout differs from the PDB");
