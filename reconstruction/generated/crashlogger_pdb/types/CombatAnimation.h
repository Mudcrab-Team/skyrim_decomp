// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatAnimation; size 0x88
#pragma once

#include "BSTArray_RE__AnimationSystemUtils__UtilsClipData_RE__BSScrapArrayAllocator_296ff22a.h"
#include "LoadedStatus.h"
#include "TESActionData.h"
struct CombatAnimation {
    TESActionData _base;
    BSTArray_RE__AnimationSystemUtils__UtilsClipData_RE__BSScrapArrayAllocator_296ff22a clipData;
    LoadedStatus loadedStatus;
    unsigned int pad84;
};
static_assert(sizeof(CombatAnimation) == 136, "CombatAnimation layout differs from the PDB");
