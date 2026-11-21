// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSCompoundFrustum; size 0xc8
#pragma once

#include "BSTArray_BSCompoundFrustumOperator_c332d121.h"
#include "BSTArray_RE__NiFrustumPlanes_3b460d56.h"
#include "NiFrustumPlanes.h"
struct NiCamera;
struct BSCompoundFrustum {
    BSTArray_RE__NiFrustumPlanes_3b460d56 planes;
    BSTArray_BSCompoundFrustumOperator_c332d121 functionOperators;
    NiFrustumPlanes viewFrustum;
    unsigned char viewPosition_raw[16];
    NiCamera* camera;
    unsigned int freePlane;
    unsigned int freeOp;
    unsigned int firstOp;
    bool skipViewFrustum;
    bool prethreaded;
    unsigned char undefined_c6[2];
};
static_assert(sizeof(BSCompoundFrustum) == 200, "BSCompoundFrustum layout differs from the PDB");
