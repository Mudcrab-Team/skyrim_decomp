// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBroadPhaseBorder; size 0x78
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_hkpEntity__hkContainerHeapAllocator.h"
#include "hkBool.h"
struct hkpBroadPhaseBorder__VFTable;
struct hkpPhantom;
struct hkpPhantomOverlapListener__VFTable;
struct hkpWorldDeletionListener__VFTable;
struct hkpWorldPostSimulationListener__VFTable;
struct hkpWorld_938ebb10;
struct hkpBroadPhaseBorder {
    hkpBroadPhaseBorder__VFTable* vftable_hkpBroadPhaseBorder_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpWorldDeletionListener__VFTable* vftable_hkpWorldDeletionListener_10;
    hkpPhantomOverlapListener__VFTable* vftable_hkpPhantomOverlapListener_18;
    hkpWorldPostSimulationListener__VFTable* vftable_hkpWorldPostSimulationListener_20;
    hkpWorld_938ebb10* m_world_28;
    hkpPhantom* m_phantoms_30[6];
    int m_type_60;
    hkBool m_postponeAndSortCallbacks_64;
    char _pad_65[3];
    hkArray_hkpEntity__hkContainerHeapAllocator m_entitiesExitingBroadPhase_68;
};
static_assert(sizeof(hkpBroadPhaseBorder) == 120, "hkpBroadPhaseBorder layout differs from the PDB");
