// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShadowDirectionalLight; size 0x5b8
#pragma once

#include "BSShadowLight.h"
#include "BSTArray_RE__NiPointer_RE__BSCullingProcess_65dc240f.h"
#include "NiPoint3.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
struct BSShadowDirectionalLight {
    BSShadowLight _base;
    NiPoint3 sunVector;
    NiPoint3 lastSunVector;
    NiPointer_RE__NiCamera_cf3a8333 fullFrustumCamera;
    BSTArray_RE__NiPointer_RE__BSCullingProcess_65dc240f fullFrustumCullingProcessArray;
    float startSplitDistances[3];
    float endSplitDistances[3];
    float sunUpdate;
    unsigned int sunUpdateMode;
};
static_assert(sizeof(BSShadowDirectionalLight) == 1464, "BSShadowDirectionalLight layout differs from the PDB");
