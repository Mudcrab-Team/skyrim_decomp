// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SummonPlacementEffect; size 0xa0
#pragma once

#include "BGSLoadGameSubBuffer.h"
#include "BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d.h"
#include "BSTSmartPointer_RE__BGSArtObjectCloneTask_c027db7e.h"
#include "NiPoint3.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "ReferenceEffect.h"
#include "SimpleAnimationGraphManagerHolder.h"
struct BGSArtObject_14762d66;
struct SummonPlacementEffect {
    ReferenceEffect _base;
    SimpleAnimationGraphManagerHolder _base_SimpleAnimationGraphManagerHolder;
    BSTEventSink_RE__BSAnimationGraphEvent_bc0d6f4d _base_BSTEventSink_RE_BSAnimationGraphEvent_;
    BGSArtObject_14762d66* artObject;
    NiPoint3 location;
    unsigned int pad7C;
    NiPointer_RE__NiAVObject_9e3aa701 artObject3D;
    BGSLoadGameSubBuffer loadedDataSubBuffer;
    BSTSmartPointer_RE__BGSArtObjectCloneTask_c027db7e cloneTask;
    bool animationComplete;
    unsigned char undefined_99[7];
};
static_assert(sizeof(SummonPlacementEffect) == 160, "SummonPlacementEffect layout differs from the PDB");
