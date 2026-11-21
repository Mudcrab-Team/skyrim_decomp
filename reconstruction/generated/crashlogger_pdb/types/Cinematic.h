// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Cinematic; size 0x40
#pragma once

#include "MultAdd_RE__NiPointer_RE__NiFloatInterpolator_625bd561.h"
#include "MultAdd_float_61cb1ae4.h"
struct Cinematic {
    float saturation;
    float brightness;
    float contrast;
    unsigned char undefined_c[4];
    MultAdd_float_61cb1ae4 contrast_2;
    MultAdd_float_61cb1ae4 empty;
    MultAdd_RE__NiPointer_RE__NiFloatInterpolator_625bd561 contrast_3;
    MultAdd_RE__NiPointer_RE__NiFloatInterpolator_625bd561 empty_2;
};
static_assert(sizeof(Cinematic) == 64, "Cinematic layout differs from the PDB");
