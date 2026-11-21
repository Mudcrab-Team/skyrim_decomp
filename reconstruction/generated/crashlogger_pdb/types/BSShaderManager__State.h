// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderManager::State; size 0x148
#pragma once

#include "NiBound_6900288c.h"
#include "NiColorA_7eee66f4.h"
#include "NiPoint2_6bdffc9f.h"
#include "NiPointer_RE__NiTexture_277bfefd.h"
#include "NiTransform.h"
struct ShadowSceneNode;
struct BSShaderManager__State {
    ShadowSceneNode* shadowSceneNode[4];
    float timerValues[5];
    NiColorA_7eee66f4 loadedRange;
    bool interior;
    bool liteBrite;
    bool characterLightEnabled;
    unsigned char pad47;
    void* unk48;
    void* unk50;
    void* unk58;
    void* unk60;
    void* unk68;
    NiPointer_RE__NiTexture_277bfefd worldMapOverlayNormal;
    NiPointer_RE__NiTexture_277bfefd worldMapOverlayNormalSnow;
    void* unk80;
    void* unk88;
    unsigned long long unk90;
    float landLOFadeSeconds;
    float invFrameBufferRange;
    float leafAnimDampenDistStartSPU;
    float leafAnimDampenDistEndSPU;
    NiPoint2_6bdffc9f oldGridArrayCenter;
    NiPoint2_6bdffc9f gridArrayCenter;
    float gridArrayLerpStart;
    unsigned int currentShaderTechnique;
    unsigned char sceneGraph;
    unsigned char undefined_c1[3];
    unsigned int debugMode;
    NiTransform directionalAmbientTransform;
    NiColorA_7eee66f4 ambientSpecular;
    float characterLightParams[4];
    bool ambientSpecularEnabled;
    unsigned char undefined_11d[3];
    unsigned int textureTransformCurrentBuffer;
    unsigned int textureTransformFlipMode;
    unsigned int cameraInWaterState;
    NiBound_6900288c cachedPlayerBound;
    unsigned int pad13C;
    unsigned int pad140;
    float waterIntersect;
};
static_assert(sizeof(BSShaderManager__State) == 328, "BSShaderManager__State layout differs from the PDB");
