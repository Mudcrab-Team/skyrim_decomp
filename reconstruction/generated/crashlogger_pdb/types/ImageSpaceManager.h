// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceManager; size 0x220
#pragma once

#include "ImageSpaceData.h"
#include "ImageSpaceTexture.h"
#include "NiColorA_7eee66f4.h"
#include "NiPointer_RE__BSImagespaceShader_3b72c412.h"
#include "NiPointer_RE__BSTriShape_e1b1b3c6.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiRect_int_2e835157.h"
#include "NiTPrimitiveArray_RE__ImageSpaceEffect_8c3f9e6d.h"
struct ImageSpaceBaseData;
struct SAOEffectParams;
struct UNK_BSImagespaceShaderISTemporalAA;
struct ImageSpaceManager {
    unsigned long long unk00;
    unsigned long long unk08;
    NiRect_int_2e835157 rect;
    NiTPrimitiveArray_RE__ImageSpaceEffect_8c3f9e6d effects;
    bool initEffects;
    unsigned char undefined_39[3];
    unsigned int unk3C;
    int unk40;
    unsigned char undefined_44[4];
    NiPointer_RE__BSTriShape_e1b1b3c6 unk48;
    NiPointer_RE__BSTriShape_e1b1b3c6 unk50;
    unsigned char unk58;
    unsigned char undefined_59[3];
    unsigned int unk5C;
    unsigned int unk60;
    unsigned char renderTarget_raw[4];
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    float unk74;
    ImageSpaceTexture unk78;
    NiColorA_7eee66f4 refractionTint;
    ImageSpaceBaseData* currentBaseData;
    ImageSpaceBaseData* overrideBaseData;
    ImageSpaceBaseData* underwaterBaseData;
    ImageSpaceBaseData* consoleBaseData;
    ImageSpaceData data;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderApplyReflections;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISApplyVolumetricLighting;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISBasicCopy;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISBlur;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISVolumetricLightingBlurHCS;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISCompositeVolumetricLighting;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISCopySubRegionCS;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISDebugSnow;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISExp;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISLightingComposite;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISPerlinNoiseCS;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderReflectionsRayTracing;
    SAOEffectParams* BSImagespaceShaderISSAOBlurH;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISSAOBlurHCS;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISSILComposite;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISSimpleColor;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISSnowSSS;
    UNK_BSImagespaceShaderISTemporalAA* BSImagespaceShaderISTemporalAA;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISUpsampleDynamicResolution;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISWaterBlend;
    NiPointer_RE__BSImagespaceShader_3b72c412 BSImagespaceShaderISUnderwaterMask;
    bool usesLDR;
    bool unk211;
    unsigned char undefined_212[6];
    NiPointer_RE__NiAVObject_9e3aa701 underwaterSplitterGeom;
};
static_assert(sizeof(ImageSpaceManager) == 544, "ImageSpaceManager layout differs from the PDB");
