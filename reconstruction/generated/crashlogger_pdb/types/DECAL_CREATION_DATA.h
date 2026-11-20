// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DECAL_CREATION_DATA; size 0xc8
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "NiMatrix3.h"
#include "NiPoint3.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
struct BGSTextureSet;
struct NiNode;
struct TESObjectCELL_f81013b3;
struct DECAL_CREATION_DATA {
    NiPoint3 origin;
    NiPoint3 direction;
    NiPoint3 surfaceNormal;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 objRef;
    NiPointer_RE__NiAVObject_9e3aa701 avObj;
    NiNode* clone;
    BGSTextureSet* texSet;
    BGSTextureSet* texSet2;
    int unk48;
    float width;
    float height;
    float depth;
    NiMatrix3 rotation;
    unsigned int unk7C;
    TESObjectCELL_f81013b3* parentCell;
    float parallaxScale;
    unsigned int unk8C;
    unsigned long long unk90;
    float shininess;
    float angleThreshold;
    float unkA0;
    float colorR;
    float colorG;
    float colorB;
    unsigned int unkB0;
    unsigned short unkB4;
    unsigned char unkB6;
    unsigned char parallax;
    unsigned char alphaTesting;
    unsigned char alphaBlending;
    unsigned char parallaxPasses;
    unsigned char unkBB;
    unsigned short unkBC;
    unsigned char unkBE;
    unsigned char undefined_bf[1];
    unsigned int unkC0;
    unsigned int padC4;
};
static_assert(sizeof(DECAL_CREATION_DATA) == 200, "DECAL_CREATION_DATA layout differs from the PDB");
