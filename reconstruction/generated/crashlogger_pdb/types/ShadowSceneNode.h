// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ShadowSceneNode; size 0x308
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSShadowLight_d4820657.h"
#include "BSTArray_RE__NiPointer_RE__BSLight_42190607.h"
#include "BSTArray_RE__NiPointer_RE__BSShadowLight_437b3816.h"
#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4.h"
#include "NiNode.h"
#include "NiPoint3.h"
#include "NiPointer_RE__BSFogProperty_f30798de.h"
struct BSLight_c6f6af80;
struct BSPortalGraph;
struct BSShadowDirectionalLight;
struct ShadowSceneNode {
    NiNode _base;
    unsigned long long unk128;
    BSTArray_RE__NiPointer_RE__BSLight_42190607 activeLights;
    BSTArray_RE__NiPointer_RE__BSShadowLight_437b3816 activeShadowLights;
    BSTArray_RE__NiPointer_RE__BSLight_42190607 lightQueueAdd;
    BSTArray_RE__NiPointer_RE__BSLight_42190607 lightQueueRemove;
    BSTArray_RE__NiPointer_RE__BSLight_42190607 unk190;
    BSSpinLock lightQueueLock;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 litGeometry;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 particleNodes;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 actorRootNodes;
    BSSpinLock objectListLock;
    BSLight_c6f6af80* sunLight;
    BSLight_c6f6af80* cloudLight;
    BSShadowDirectionalLight* sunShadowDirLight;
    unsigned char sceneGraphIndex;
    bool disableLightUpdate;
    bool wireframe;
    bool opaqueWireframe;
    unsigned int pad21C;
    NiPointer_RE__BSFogProperty_f30798de fogProperty;
    BSPortalGraph* portalGraph;
    BSTArray_RE__BSShadowLight_d4820657 shadowLightsAccum;
    unsigned int firstPersonShadowMask;
    unsigned int unk24C;
    unsigned long long unk250;
    unsigned long long unk258;
    unsigned long long unk260;
    unsigned long long unk268;
    unsigned long long unk270;
    unsigned long long unk278;
    unsigned long long unk280;
    unsigned long long unk288;
    unsigned long long unk290;
    unsigned long long unk298;
    unsigned long long unk2A0;
    unsigned long long unk2A8;
    unsigned long long unk2B0;
    unsigned long long unk2B8;
    unsigned long long unk2C0;
    unsigned long long unk2C8;
    unsigned long long unk2D0;
    unsigned long long unk2D8;
    unsigned long long unk2E0;
    NiPoint3 lightingOffset;
    NiPoint3 cameraPos;
    bool allowLightRemoveQueues;
    unsigned char pad301;
    unsigned short pad302;
    float windMagnitude;
};
static_assert(sizeof(ShadowSceneNode) == 776, "ShadowSceneNode layout differs from the PDB");
