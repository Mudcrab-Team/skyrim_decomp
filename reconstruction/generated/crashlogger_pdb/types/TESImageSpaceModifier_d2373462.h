// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpaceModifier; size 0x2e0
// one of 2 different PDB types sharing this name
#pragma once

#include "BSString.h"
#include "NiPointer_NiColorInterpolator_ed976e23.h"
#include "NiPointer_NiFloatInterpolator_1bd1ee90.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESImageSpaceModifier__BaseData.h"
#include "TESImageSpaceModifier__BloomInstanceData.h"
#include "TESImageSpaceModifier__CinematicInstanceData.h"
#include "TESImageSpaceModifier__DOFInstanceData.h"
#include "TESImageSpaceModifier__HDRInstanceData.h"
#include "TESImageSpaceModifier__RadialBlurInstanceData.h"
struct TESImageSpaceModifier__VFTable;
struct TESImageSpaceModifier_d2373462 {
    TESImageSpaceModifier__VFTable* vftable_TESImageSpaceModifier_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESImageSpaceModifier__BaseData ImageSpaceData_20;
    char _pad_114[4];
    TESImageSpaceModifier__HDRInstanceData Hdr_118;
    TESImageSpaceModifier__BloomInstanceData Bloom_1F8;
    TESImageSpaceModifier__CinematicInstanceData Cinematic_228;
    NiPointer_NiFloatInterpolator_1bd1ee90 BlurRadius_268;
    NiPointer_NiFloatInterpolator_1bd1ee90 DoubleVisionStrength_270;
    NiPointer_NiColorInterpolator_ed976e23 TintColor_278;
    NiPointer_NiColorInterpolator_ed976e23 FadeColor_280;
    TESImageSpaceModifier__RadialBlurInstanceData RadialBlur_288;
    TESImageSpaceModifier__DOFInstanceData Dof_2B0;
    NiPointer_NiColorInterpolator_ed976e23 MotionBlurStrength_2C8;
    BSString FormEditorId_2D0;
};
static_assert(sizeof(TESImageSpaceModifier_d2373462) == 736, "TESImageSpaceModifier_d2373462 layout differs from the PDB");
