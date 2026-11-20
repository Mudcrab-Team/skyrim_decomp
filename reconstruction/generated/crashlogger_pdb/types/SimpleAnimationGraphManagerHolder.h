// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SimpleAnimationGraphManagerHolder; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTSmartPointer_RE__BSAnimationGraphManager_8b67f94f.h"
#include "IAnimationGraphManagerHolder_f623b5a9.h"
#include "NiPointer_RE__SimpleAnimationGraphManagerLoadingTask_5fc0528f.h"
struct SimpleAnimationGraphManagerHolder {
    IAnimationGraphManagerHolder_f623b5a9 _base;
    BSTSmartPointer_RE__BSAnimationGraphManager_8b67f94f animationGraphManager;
    NiPointer_RE__SimpleAnimationGraphManagerLoadingTask_5fc0528f loadingTask;
};
static_assert(sizeof(SimpleAnimationGraphManagerHolder) == 24, "SimpleAnimationGraphManagerHolder layout differs from the PDB");
