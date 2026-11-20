// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpaceModifier__BaseData; size 0xf4
#pragma once

#include "NiPoint2.h"
#include "TESImageSpaceModifier__BloomBaseData.h"
#include "TESImageSpaceModifier__CinematicBaseData.h"
#include "TESImageSpaceModifier__DOFBaseData.h"
#include "TESImageSpaceModifier__HDRBaseData.h"
struct TESImageSpaceModifier__BaseData {
    bool Animatable_0;
    char _pad_1[3];
    float Duration_4;
    TESImageSpaceModifier__HDRBaseData Hdr_8;
    TESImageSpaceModifier__BloomBaseData Bloom_78;
    TESImageSpaceModifier__CinematicBaseData Cinematic_90;
    unsigned int TintColor_B0;
    int BlurRadius_B4;
    int DoubleVisionStrength_B8;
    int RadialBlurStrength_BC;
    int RadialBlurRampUp_C0;
    int RadialBlurStart_C4;
    bool UseTargetForRadialBlur_C8;
    char _pad_C9[3];
    NiPoint2 RadialBlurCenter_CC;
    TESImageSpaceModifier__DOFBaseData Dof_D4;
    int RadialBlurRampDown_E4;
    int RadialBlurDownStart_E8;
    unsigned int FadeColor_EC;
    int MotionBlurStrength_F0;
};
static_assert(sizeof(TESImageSpaceModifier__BaseData) == 244, "TESImageSpaceModifier__BaseData layout differs from the PDB");
