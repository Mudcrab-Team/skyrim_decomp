// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpaceModifier__HDRInstanceData; size 0xe0
#pragma once

#include "TESImageSpaceModifier__MinMax_NiPointer_NiFloatInterpolator.h"
#include "TESImageSpaceModifier__MultAdd_NiPointer_NiFloatInterpolator.h"
struct TESImageSpaceModifier__HDRInstanceData {
    TESImageSpaceModifier__MultAdd_NiPointer_NiFloatInterpolator EyeAdaptSpeed_0;
    TESImageSpaceModifier__MultAdd_NiPointer_NiFloatInterpolator BloomBlurRadius_10;
    TESImageSpaceModifier__MultAdd_NiPointer_NiFloatInterpolator BloomThreshold_20;
    TESImageSpaceModifier__MultAdd_NiPointer_NiFloatInterpolator BloomScale_30;
    TESImageSpaceModifier__MinMax_NiPointer_NiFloatInterpolator TargetLum_40;
    TESImageSpaceModifier__MultAdd_NiPointer_NiFloatInterpolator SunlightScale_60;
    TESImageSpaceModifier__MultAdd_NiPointer_NiFloatInterpolator SkyScale_70;
    TESImageSpaceModifier__MultAdd_NiPointer_NiFloatInterpolator Empty_80[6];
};
static_assert(sizeof(TESImageSpaceModifier__HDRInstanceData) == 224, "TESImageSpaceModifier__HDRInstanceData layout differs from the PDB");
