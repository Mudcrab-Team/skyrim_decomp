// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: INTERIOR_DATA; size 0x60
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSDirectionalAmbientLightingColors.h"
#include "Color.h"
#include "EnumSet_RE__INTERIOR_DATA__Inherit_unsigned_int_245df68a.h"
struct INTERIOR_DATA_9a5b4bee {
    Color ambient;
    Color directional;
    Color fogColorNear;
    float fogNear;
    float fogFar;
    unsigned int directionalXY;
    unsigned int directionalZ;
    float directionalFade;
    float clipDist;
    float fogPower;
    BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;
    Color fogColorFar;
    float fogClamp;
    float lightFadeStart;
    float lightFadeEnd;
    EnumSet_RE__INTERIOR_DATA__Inherit_unsigned_int_245df68a lightingTemplateInheritanceFlags;
    unsigned int unk5C;
};
static_assert(sizeof(INTERIOR_DATA_9a5b4bee) == 96, "INTERIOR_DATA_9a5b4bee layout differs from the PDB");
