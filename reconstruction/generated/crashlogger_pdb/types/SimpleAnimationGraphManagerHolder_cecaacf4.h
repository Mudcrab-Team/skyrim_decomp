// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SimpleAnimationGraphManagerHolder; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTSmartPointer_BSAnimationGraphManager_dd7e7e8e.h"
#include "NiPointer_SimpleAnimationGraphManagerLoadingTask_a67413f3.h"
struct SimpleAnimationGraphManagerHolder__VFTable;
struct SimpleAnimationGraphManagerHolder_cecaacf4 {
    SimpleAnimationGraphManagerHolder__VFTable* vftable_SimpleAnimationGraphManagerHolder_0;
    BSTSmartPointer_BSAnimationGraphManager_dd7e7e8e AnimationGraphManager_8;
    NiPointer_SimpleAnimationGraphManagerLoadingTask_a67413f3 LoadingTask_10;
};
static_assert(sizeof(SimpleAnimationGraphManagerHolder_cecaacf4) == 24, "SimpleAnimationGraphManagerHolder_cecaacf4 layout differs from the PDB");
