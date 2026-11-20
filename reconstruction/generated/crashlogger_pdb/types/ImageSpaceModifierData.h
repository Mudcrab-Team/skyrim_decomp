// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceModifierData; size 0xf4
#pragma once

#include "NiPoint2_6bdffc9f.h"
struct ImageSpaceModifierData {
    bool animatable;
    unsigned char pad01;
    unsigned short pad02;
    float duration;
    unsigned char hdr_raw[112];
    unsigned char bloom_raw[24];
    unsigned char cinematic_raw[32];
    unsigned int tintColor;
    unsigned int blurRadius;
    unsigned int doubleVisionStrength;
    unsigned int radialBlurStrength;
    unsigned int radialBlurRampUp;
    unsigned int radialBlurStart;
    bool useTargetForRadialBlur;
    unsigned char padC9;
    unsigned short padCA;
    NiPoint2_6bdffc9f radialBlurCenter;
    unsigned char dof_raw[16];
    unsigned int radialBlurRampDown;
    unsigned int radialBlurDownStart;
    unsigned int fadeColor;
    unsigned int motionBlurStrength;
};
static_assert(sizeof(ImageSpaceModifierData) == 244, "ImageSpaceModifierData layout differs from the PDB");
