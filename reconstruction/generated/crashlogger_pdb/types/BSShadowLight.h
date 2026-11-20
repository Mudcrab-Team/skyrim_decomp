// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShadowLight; size 0x560
#pragma once

#include "BSLight_c6f6af80.h"
#include "BSTArray_RE__BSShadowLight__ShadowmapDescriptor_9ba41cb1.h"
#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4.h"
#include "NiRect_unsigned_int_55e2d057.h"
struct BSShadowLight {
    BSLight_c6f6af80 _base;
    unsigned int shadowMapCount;
    unsigned int unk144;
    BSTArray_RE__BSShadowLight__ShadowmapDescriptor_9ba41cb1 shadowmapDescriptors;
    unsigned char focusShadowmapDescriptors_raw[960];
    unsigned int maskIndex;
    unsigned int accumulatedIndex;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 sceneAccumArray;
    float shadowBiasScale;
    NiRect_unsigned_int_55e2d057 projectedBoundingBox;
    unsigned int sceneGraphIndex;
    bool drawFocusShadows;
    unsigned char pad559;
    unsigned char pad55A;
    unsigned char undefined_55b[1];
    unsigned int pad55B;
};
static_assert(sizeof(BSShadowLight) == 1376, "BSShadowLight layout differs from the PDB");
