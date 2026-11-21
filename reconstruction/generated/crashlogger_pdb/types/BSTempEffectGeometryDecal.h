// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTempEffectGeometryDecal; size 0xb8
#pragma once

#include "BSTSmartPointer_RE__QueuedTempEffect_3d09ab08.h"
#include "BSTempEffect.h"
#include "NiMatrix3.h"
#include "NiPoint3.h"
#include "NiPointer_RE__BSGeometry_933f0714.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
struct BGSTextureSet;
struct BSTempEffectGeometryDecal {
    BSTempEffect _base;
    NiPointer_RE__BSGeometry_933f0714 decal;
    NiPointer_RE__BSGeometry_933f0714 attachedGeometry;
    NiPointer_RE__NiNode_28171d5b attachedGeometryParent;
    NiPointer_RE__NiNode_28171d5b decalNode;
    BSTSmartPointer_RE__QueuedTempEffect_3d09ab08 queuedDecal;
    BGSTextureSet* texSet;
    BGSTextureSet* texSet2;
    NiMatrix3 rotation;
    NiPoint3 origin;
    NiPoint3 direction;
    float width;
    unsigned int unkA8;
    unsigned int flags;
    bool unkB0;
    unsigned char undefined_b1[7];
};
static_assert(sizeof(BSTempEffectGeometryDecal) == 184, "BSTempEffectGeometryDecal layout differs from the PDB");
