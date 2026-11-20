// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpaceModifier__RadialBlurInstanceData; size 0x28
#pragma once

#include "NiPointer_NiFloatInterpolator_1bd1ee90.h"
struct TESImageSpaceModifier__RadialBlurInstanceData {
    NiPointer_NiFloatInterpolator_1bd1ee90 Strength_0;
    NiPointer_NiFloatInterpolator_1bd1ee90 RampUp_8;
    NiPointer_NiFloatInterpolator_1bd1ee90 Start_10;
    NiPointer_NiFloatInterpolator_1bd1ee90 RampDown_18;
    NiPointer_NiFloatInterpolator_1bd1ee90 DownStart_20;
};
static_assert(sizeof(TESImageSpaceModifier__RadialBlurInstanceData) == 40, "TESImageSpaceModifier__RadialBlurInstanceData layout differs from the PDB");
