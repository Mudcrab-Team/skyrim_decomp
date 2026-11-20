// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTempEffectParticle; size 0xf0
#pragma once

#include "BSSoundHandle.h"
#include "BSTSmartPointer_RE__BGSParticleObjectCloneTask_a5813c0f.h"
#include "BSTempEffect.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "NiTransform.h"
struct BGSImpactData;
struct BSTempEffectParticle {
    BSTempEffect _base;
    NiPointer_RE__NiAVObject_9e3aa701 particleObject;
    BSTSmartPointer_RE__BGSParticleObjectCloneTask_a5813c0f cloneTask;
    unsigned char* modelName;
    NiPointer_RE__NiNode_28171d5b dynamicCellNode;
    NiTransform particleEffectTransform;
    unsigned int flags;
    NiPointer_RE__NiAVObject_9e3aa701 spawnNode;
    NiTransform spawnNodeTransform;
    unsigned int padC4;
    BGSImpactData* impactData;
    BSSoundHandle sound1;
    BSSoundHandle sound2;
    unsigned char unkE8;
    unsigned char padE9;
    unsigned short unkEA;
    unsigned int unkEC;
};
static_assert(sizeof(BSTempEffectParticle) == 240, "BSTempEffectParticle layout differs from the PDB");
