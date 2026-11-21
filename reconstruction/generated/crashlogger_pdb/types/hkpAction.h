// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAction; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkStringPtr.h"
struct hkpAction__VFTable;
struct hkpSimulationIsland_f82b975f;
struct hkpWorld_938ebb10;
struct hkpAction {
    hkpAction__VFTable* vftable_hkpAction_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpWorld_938ebb10* m_world_10;
    hkpSimulationIsland_f82b975f* m_island_18;
    unsigned long long m_userData_20;
    hkStringPtr m_name_28;
};
static_assert(sizeof(hkpAction) == 48, "hkpAction layout differs from the PDB");
