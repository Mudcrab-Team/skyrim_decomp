// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HDR; size 0xe0
#pragma once

#include "MultAdd_RE__NiPointer_RE__NiFloatInterpolator_625bd561.h"
#include "MultAdd_float_61cb1ae4.h"
struct HDR {
    float eyeAdaptSpeed;
    float bloomBlurRadius;
    float bloomThreshold;
    float bloomScale;
    float receiveBloomThreshold;
    float white;
    float sunlightScale;
    float skyScale;
    float eyeAdaptStrength;
    unsigned char undefined_24[12];
    MultAdd_float_61cb1ae4 sunlightScale_2;
    MultAdd_float_61cb1ae4 skyScale_2;
    unsigned char undefined_40[32];
    MultAdd_RE__NiPointer_RE__NiFloatInterpolator_625bd561 sunlightScale_3;
    MultAdd_RE__NiPointer_RE__NiFloatInterpolator_625bd561 skyScale_3;
    unsigned char empty_raw[96];
};
static_assert(sizeof(HDR) == 224, "HDR layout differs from the PDB");
