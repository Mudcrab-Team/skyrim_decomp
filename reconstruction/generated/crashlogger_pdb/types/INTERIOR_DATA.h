// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: INTERIOR_DATA; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSDirectionalAmbientLightingColors_bbed7424.h"
#include "Color_aa361e09.h"
#include "Inherit.h"
struct INTERIOR_DATA {
    Color_aa361e09 ambient;
    Color_aa361e09 directional;
    Color_aa361e09 fogColorNear;
    float fogNear;
    float fogFar;
    unsigned int directionalXY;
    unsigned int directionalZ;
    float directionalFade;
    float clipDist;
    float fogPower;
    BGSDirectionalAmbientLightingColors_bbed7424 directionalAmbientLightingColors;
    Color_aa361e09 fogColorFar;
    float fogClamp;
    float lightFadeStart;
    float lightFadeEnd;
    Inherit lightingTemplateInheritanceFlags;
    unsigned int unk5C;
};
static_assert(sizeof(INTERIOR_DATA) == 96, "INTERIOR_DATA layout differs from the PDB");
