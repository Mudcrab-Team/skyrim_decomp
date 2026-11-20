// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraContainerChanges; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct InventoryChanges;
struct ExtraContainerChanges {
    BSExtraData_4ca6af76 _base;
    InventoryChanges* changes;
};
static_assert(sizeof(ExtraContainerChanges) == 24, "ExtraContainerChanges layout differs from the PDB");
