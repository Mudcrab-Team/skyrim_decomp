// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTempEffectSimpleDecal; size 0x1e0
#pragma once

#include "BSTArray_void_9eb8914c.h"
#include "BSTempEffect.h"
#include "NiColor_e5e1ad7d.h"
#include "NiFrustumPlanes.h"
#include "NiMatrix3.h"
#include "NiPoint3.h"
#include "NiPointer_RE__BGSDecalNode_6727eee3.h"
#include "NiPointer_RE__BSGeometry_933f0714.h"
#include "NiPointer_RE__BSTriShape_e1b1b3c6.h"
struct BGSTextureSet;
struct OcclusionQuery;
struct BSTempEffectSimpleDecal {
    BSTempEffect _base;
    unsigned char unk30;
    unsigned char unk31;
    bool unk32;
    unsigned char undefined_33[1];
    unsigned short unk36;
    unsigned char undefined_36[2];
    OcclusionQuery* occlusionQuery;
    unsigned int unk40;
    unsigned int unk44;
    NiPointer_RE__BSGeometry_933f0714 effect3D;
    unsigned int state;
    bool permanent;
    unsigned char unk55;
    bool unk56;
    unsigned char unk57;
    BGSTextureSet* textureSet;
    BGSTextureSet* textureSet2;
    NiPoint3 origin1;
    NiPoint3 direction1;
    NiPoint3 origin2;
    NiPoint3 direction2;
    NiFrustumPlanes planes;
    unsigned long long unk108;
    unsigned long long unk110;
    unsigned long long unk118;
    unsigned long long unk120;
    unsigned long long unk128;
    unsigned long long unk130;
    unsigned long long unk138;
    unsigned long long unk140;
    unsigned long long unk148;
    unsigned long long unk150;
    BSTArray_void_9eb8914c unk158;
    NiPointer_RE__BGSDecalNode_6727eee3 decalNode;
    NiPointer_RE__BSTriShape_e1b1b3c6 avShape;
    float unk180;
    NiMatrix3 emitterRotation;
    unsigned int unk1A8;
    float width;
    float height;
    float depth;
    unsigned char subTextureIndex;
    bool parallaxOcc;
    unsigned char unk1BA;
    unsigned char unk1BB;
    float parallaxScale;
    unsigned char parallaxPasses;
    bool alphaBlending;
    bool enableBlending;
    unsigned char unk1C3;
    float shininess;
    NiColor_e5e1ad7d color;
    bool unk1D4;
    bool twoSided;
    bool unk1D6;
    unsigned char unk1D7;
    unsigned int unk1D8;
    unsigned int unk1DC;
};
static_assert(sizeof(BSTempEffectSimpleDecal) == 480, "BSTempEffectSimpleDecal layout differs from the PDB");
