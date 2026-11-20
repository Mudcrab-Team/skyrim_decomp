// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaAnimationBinding; size 0x48
#pragma once

#include "hkArray_short_4499914d.h"
#include "hkRefPtr_RE__hkaAnimation_2e3b82ae.h"
#include "hkReferencedObject.h"
#include "hkStringPtr_33d8e88b.h"
struct hkaAnimationBinding {
    hkReferencedObject _base;
    hkStringPtr_33d8e88b originalSkeletonName;
    hkRefPtr_RE__hkaAnimation_2e3b82ae animation;
    hkArray_short_4499914d transformTrackToBoneIndices;
    hkArray_short_4499914d floatTrackToFloatSlotIndices;
    unsigned char blendHint;  // BlendHint in the PDB is wider than this slot
    unsigned char pad41[7];
};
static_assert(sizeof(hkaAnimationBinding) == 72, "hkaAnimationBinding layout differs from the PDB");
