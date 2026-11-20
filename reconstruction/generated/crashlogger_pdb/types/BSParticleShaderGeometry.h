// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSParticleShaderGeometry; size 0x1a0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "NiAVObjectFlag.h"
#include "NiBound.h"
#include "NiExtraDataList.h"
#include "NiPointer_NiCollisionObject_93dfa728.h"
#include "NiPointer_NiProperty_70f113a4.h"
#include "NiPointer_NiSkinInstance_92680d0d.h"
#include "NiPointer_NiTimeController_4d1e262c.h"
#include "NiTransform_333059e5.h"
struct BSParticleShaderGeometry__VFTable;
struct NiNode_9cd97e9e;
struct TESObjectREFR;
#pragma pack(push, 1)
struct BSParticleShaderGeometry {
    NiTransform_333059e5 FrameTransform_B0;
    NiPointer_NiTimeController_4d1e262c TimeControllers_18;
    NiPointer_NiProperty_70f113a4 Properties_120[2];
    unsigned char undefined_4c[16];
    NiBound ModelBound_110;
    unsigned char undefined_6c[4];
    char _pad_15C[36];
    NiPointer_NiSkinInstance_92680d0d Skin_130;
    float accelerationAlongNormal;
    float initialVelocity1;
    NiPointer_NiCollisionObject_93dfa728 Collidable_40;
    unsigned long long VertexDesc_148;
    NiExtraDataList ExtraList_20;
    float FadeAmount_100;
    NiTransform_333059e5 LocalTransform_48;
    TESObjectREFR* OwnerObject_F8;
    int Index_38;
    unsigned int LastUpdatedFrameCounter_104;
    char _pad_151[7];
    unsigned short TriangleCount_158;
    NiTransform_333059e5 WorldTransform_7C;
    NiBound WorldBound_E4;
    unsigned char undefined_159[4];
    void* RendererData_138;
    BSFixedString Name_10;
    NiNode_9cd97e9e* Parent_30;
    char _pad_3C[4];
    char _pad_108[8];
    unsigned short VertexCount_15A;
    char GeometryType_150;
    char _pad_8[8];
    BSParticleShaderGeometry__VFTable* vftable_BSParticleShaderGeometry_0;
    NiAVObjectFlag NiAVFlags_F4;
    char _pad_140[8];
};
#pragma pack(pop)
static_assert(sizeof(BSParticleShaderGeometry) == 416, "BSParticleShaderGeometry layout differs from the PDB");
