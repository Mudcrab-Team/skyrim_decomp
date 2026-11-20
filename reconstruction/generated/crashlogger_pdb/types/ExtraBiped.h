// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraBiped; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTSmartPointer_RE__BipedAnim_9198d0c2.h"
struct ExtraBiped {
    BSExtraData_4ca6af76 _base;
    BSTSmartPointer_RE__BipedAnim_9198d0c2 biped;
};
static_assert(sizeof(ExtraBiped) == 24, "ExtraBiped layout differs from the PDB");
