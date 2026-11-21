// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DrawWorld; size 0x58
#pragma once

#include "NiPoint3.h"
struct NiAVObject;
struct SceneGraph;
struct ShadowSceneNode;
struct Sun;
struct DrawWorld {
    NiPoint3 firstPersonNodePosition;
    float firstPersonFOV;
    float worldFOV;
    unsigned int pad14;
    NiAVObject* pcFirstPerson3D;
    NiAVObject* pcThirdPerson3D;
    SceneGraph* worldSceneGraph;
    ShadowSceneNode* mainShadowSceneNode;
    Sun* sun;
    unsigned int activeShadowLightCount;
    unsigned int shadowLightCount;
    unsigned int shadowLightMaskIndex;
    unsigned int shadowLightMask;
    bool disableUpdateFOV;
    bool disableSunShadows;
    bool unk52;
    unsigned char undefined_53[5];
};
static_assert(sizeof(DrawWorld) == 88, "DrawWorld layout differs from the PDB");
