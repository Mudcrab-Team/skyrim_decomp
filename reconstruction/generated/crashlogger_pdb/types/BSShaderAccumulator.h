// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderAccumulator; size 0x180
#pragma once

#include "BSFadeNodeMap.h"
#include "NiAlphaAccumulator.h"
#include "NiColorA_7eee66f4.h"
#include "NiPoint3.h"
#include "RENDER_MODE.h"
#include "SunOcclusionTest.h"
struct BSBatchRenderer;
struct NiRefObject;
struct ShadowSceneNode;
struct BSShaderAccumulator {
    NiAlphaAccumulator _base;
    unsigned char undefined_58[4];
    bool useEqualDepthTest;
    unsigned char undefined_5d[3];
    unsigned int sunPixelCount;
    bool waitingForSunQuery;
    unsigned char undefined_65[3];
    float percentSunOccludedStored;
    unsigned char pad6C[4];
    SunOcclusionTest sunOcclusionTests[3];
    bool unkB8;
    bool noFade;
    bool unkBA;
    unsigned char padBB[5];
    unsigned char unkC0[16];
    BSFadeNodeMap fadeNodeMap;
    unsigned char unkF0[16];
    void* unk100;
    NiRefObject* unk108;
    unsigned int unk110;
    bool unk114;
    unsigned char undefined_115[3];
    NiColorA_7eee66f4 silhouetteColor;
    bool firstPerson;
    bool unk129;
    bool unk12A;
    bool unk12B;
    bool drawDecals;
    bool isShadowMapAccumulator;
    bool isDirectionalShadowMap;
    unsigned char undefined_12f[1];
    BSBatchRenderer* batchRenderer;
    unsigned int currentPass;
    unsigned int currentBucket;
    bool currentActive;
    unsigned char _pad[7];
    ShadowSceneNode* activeShadowSceneNode;
    RENDER_MODE renderMode;
    unsigned char undefined_154[4];
    NiRefObject* unk158;
    unsigned int flagOverrideMode;
    unsigned int flagOverrideMask;
    unsigned int shadowMapIndex;
    NiPoint3 eyePosition;
    unsigned char _pad3[8];
};
static_assert(sizeof(BSShaderAccumulator) == 384, "BSShaderAccumulator layout differs from the PDB");
