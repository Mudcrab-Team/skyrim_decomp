// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Pathing; size 0xb8
#pragma once

#include "BSPathing.h"
#include "BSPathingCellManager.h"
#include "BSSpinLock.h"
#include "BSTArray_RE__BSTTuple_unsigned_long_long_RE__BSTSmartPointer_RE__PathingCell_20de2d44.h"
#include "BSTEventSink_RE__CellAttachDetachEvent_ce86c546.h"
#include "BSTScatterTable_RE__BSCRC32_RE__PathingCellInfo_std__equal_to_RE__PathingCellInfo_RE__B_5269f7f3.h"
#include "BSTSingletonSDM_RE__Pathing_95f810fa.h"
#include "MovementManager.h"
struct Pathing {
    BSPathing _base;
    BSPathingCellManager _base_BSPathingCellManager;
    BSTEventSink_RE__CellAttachDetachEvent_ce86c546 _base_BSTEventSink_RE_CellAttachDetachEvent_;
    BSTSingletonSDM_RE__Pathing_95f810fa _base_BSTSingletonSDM_RE_Pathing_;
    unsigned char undefined_29[7];
    MovementManager _base_MovementManager;
    BSSpinLock cellCacheLock;
    BSTScatterTable_RE__BSCRC32_RE__PathingCellInfo_std__equal_to_RE__PathingCellInfo_RE__B_5269f7f3 loadedCells;
    BSTArray_RE__BSTTuple_unsigned_long_long_RE__BSTSmartPointer_RE__PathingCell_20de2d44 recentCells;
};
static_assert(sizeof(Pathing) == 184, "Pathing layout differs from the PDB");
