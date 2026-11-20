// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpaceModifier; size 0x2e0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "Bloom.h"
#include "Cinematic.h"
#include "DOF.h"
#include "HDR.h"
#include "ImageSpaceModifierData.h"
#include "NiPointer_RE__NiColorInterpolator_34694f23.h"
#include "NiPointer_RE__NiFloatInterpolator_1dc0cc15.h"
#include "RadialBlur.h"
#include "TESForm.h"
struct TESImageSpaceModifier {
    TESForm _base;
    ImageSpaceModifierData data;
    unsigned int pad114;
    HDR hdr;
    Bloom bloom;
    unsigned char undefined_210[24];
    Cinematic cinematic;
    NiPointer_RE__NiFloatInterpolator_1dc0cc15 blurRadius;
    NiPointer_RE__NiFloatInterpolator_1dc0cc15 doubleVisionStrength;
    NiPointer_RE__NiColorInterpolator_34694f23 tintColor;
    NiPointer_RE__NiColorInterpolator_34694f23 fadeColor;
    RadialBlur radialBlur;
    DOF dof;
    unsigned char undefined_2c0[8];
    NiPointer_RE__NiColorInterpolator_34694f23 motionBlurStrength;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce formEditorID;
};
static_assert(sizeof(TESImageSpaceModifier) == 736, "TESImageSpaceModifier layout differs from the PDB");
