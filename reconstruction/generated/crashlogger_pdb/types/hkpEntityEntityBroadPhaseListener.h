// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpEntityEntityBroadPhaseListener; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpBroadPhaseListener__VFTable;
struct hkpEntityEntityBroadPhaseListener__VFTable;
struct hkpWorld_938ebb10;
struct hkpEntityEntityBroadPhaseListener {
    hkpEntityEntityBroadPhaseListener__VFTable* vftable_hkpEntityEntityBroadPhaseListener_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpBroadPhaseListener__VFTable* vftable_hkpBroadPhaseListener_10;
    hkpWorld_938ebb10* m_world_18;
};
static_assert(sizeof(hkpEntityEntityBroadPhaseListener) == 32, "hkpEntityEntityBroadPhaseListener layout differs from the PDB");
