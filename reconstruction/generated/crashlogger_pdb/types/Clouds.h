// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Clouds; size 0x520
#pragma once

#include "NiColor_e5e1ad7d.h"
#include "NiPointer_RE__BSGeometry_933f0714.h"
#include "NiPointer_RE__NiTexture_277bfefd.h"
#include "SkyObject.h"
struct TESWeather;
struct Clouds {
    SkyObject _base;
    NiPointer_RE__BSGeometry_933f0714 clouds[32];
    unsigned long long unk110[32];
    NiPointer_RE__NiTexture_277bfefd transTexture[32];
    NiColor_e5e1ad7d colors[32];
    float alphas[32];
    unsigned short numLayers;
    bool forceUpdate;
    bool unk513;
    unsigned int pad514;
    TESWeather* lastWeather;
};
static_assert(sizeof(Clouds) == 1312, "Clouds layout differs from the PDB");
