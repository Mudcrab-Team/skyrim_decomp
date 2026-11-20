// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ShaderReferenceEffect; size 0x138
#pragma once

#include "BSSoundHandle.h"
#include "BSTArray_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE_8e0cadc8.h"
#include "BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4.h"
#include "BSTArray_RE__ShaderReferenceEffect__ParticleShader_0bad5a5c.h"
#include "BSTArray_RE__ShaderReferenceEffect__TextureRequest_0ba1bd4d.h"
#include "BSTArray_void_9eb8914c.h"
#include "Flag_a4a94b8a.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
#include "ReferenceEffect.h"
struct BSEffectShaderData_e3d33052;
struct TESBoundObject_fc790793;
struct TESEffectShader;
struct ShaderReferenceEffect {
    ReferenceEffect _base;
    BSTArray_RE__ShaderReferenceEffect__TextureRequest_0ba1bd4d textureRequests;
    BSTArray_RE__NiPointer_RE__NiAVObject_f418c101_e50491e4 addonObjects;
    BSTArray_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE_8e0cadc8 modelHandles;
    BSTArray_RE__ShaderReferenceEffect__ParticleShader_0bad5a5c particleShaders;
    BSTArray_void_9eb8914c unk0A8;
    BSSoundHandle soundHandle;
    unsigned int pad0CC;
    NiPointer_RE__NiSourceTexture_cf356212 particleShaderTexture;
    NiPointer_RE__NiSourceTexture_cf356212 particlePaletteTexture;
    NiPointer_RE__NiSourceTexture_cf356212 fillTexture;
    NiPointer_RE__NiSourceTexture_cf356212 holesTexture;
    NiPointer_RE__NiSourceTexture_cf356212 paletteTexture;
    NiPointer_RE__NiAVObject_9e3aa701 lastRootNode;
    TESBoundObject_fc790793* wornObject;
    TESEffectShader* effectData;
    BSEffectShaderData_e3d33052* effectShaderData;
    NiPointer_RE__NiAVObject_9e3aa701 targetRoot;
    float alphaTimer;
    float addonAlpha;
    float addonScale;
    float effectShaderAge;
    Flag_a4a94b8a flags;
    unsigned int pushCount;
};
static_assert(sizeof(ShaderReferenceEffect) == 312, "ShaderReferenceEffect layout differs from the PDB");
