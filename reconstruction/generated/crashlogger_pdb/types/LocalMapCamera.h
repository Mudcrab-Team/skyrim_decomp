// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LocalMapCamera; size 0x68
#pragma once

#include "BSTSmartPointer_RE__LocalMapCamera__DefaultState_ee1b84cb.h"
#include "NiPoint3.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
#include "TESCamera.h"
struct LocalMapCamera {
    TESCamera _base;
    NiPoint3 maxExtent;
    NiPoint3 minExtent;
    BSTSmartPointer_RE__LocalMapCamera__DefaultState_ee1b84cb defaultState;
    NiPointer_RE__NiCamera_cf3a8333 camera;
    float zRotation;
    unsigned int pad64;
};
static_assert(sizeof(LocalMapCamera) == 104, "LocalMapCamera layout differs from the PDB");
