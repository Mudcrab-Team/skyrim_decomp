// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpaceModifier__HDRBaseData; size 0x70
#pragma once

#include "TESImageSpaceModifier__MinMax_float.h"
#include "TESImageSpaceModifier__MultAdd_float.h"
struct TESImageSpaceModifier__HDRBaseData {
    TESImageSpaceModifier__MultAdd_float EyeAdaptSpeed_0;
    TESImageSpaceModifier__MultAdd_float BloomBlurRadius_8;
    TESImageSpaceModifier__MultAdd_float BloomThreshold_10;
    TESImageSpaceModifier__MultAdd_float BloomScale_18;
    TESImageSpaceModifier__MinMax_float TargetLum_20;
    TESImageSpaceModifier__MultAdd_float SunlightScale_30;
    TESImageSpaceModifier__MultAdd_float SkyScale_38;
    TESImageSpaceModifier__MultAdd_float Empty_40[6];
};
static_assert(sizeof(TESImageSpaceModifier__HDRBaseData) == 112, "TESImageSpaceModifier__HDRBaseData layout differs from the PDB");
