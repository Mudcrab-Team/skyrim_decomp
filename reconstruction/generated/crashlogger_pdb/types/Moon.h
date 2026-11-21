// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Moon; size 0xd8
#pragma once

#include "BSString.h"
#include "NiPointer_RE__BSTriShape_e1b1b3c6.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "SkyObject.h"
#include "UpdateStatus.h"
struct Moon {
    SkyObject _base;
    NiPointer_RE__NiNode_28171d5b moonNode;
    NiPointer_RE__NiNode_28171d5b shadowNode;
    NiPointer_RE__BSTriShape_e1b1b3c6 moonMesh;
    NiPointer_RE__BSTriShape_e1b1b3c6 shadowMesh;
    BSString stateTextures[8];
    float angleFadeStart;
    float angleFadeEnd;
    float angleShadowEarlyFade;
    float speed;
    float zOffset;
    unsigned int size;
    UpdateStatus updateMoonTexture;
    float unkCC;
    float unkD0;
    unsigned int padD4;
};
static_assert(sizeof(Moon) == 216, "Moon layout differs from the PDB");
