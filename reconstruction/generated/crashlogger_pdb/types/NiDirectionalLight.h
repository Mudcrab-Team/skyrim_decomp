// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiDirectionalLight; size 0x158
#pragma once

#include "NiColor_e5e1ad7d.h"
#include "NiLight.h"
#include "NiPoint3.h"
struct NiDirectionalLight {
    NiLight _base;
    NiPoint3 worldDir;
    NiColor_e5e1ad7d effectColor;
};
static_assert(sizeof(NiDirectionalLight) == 344, "NiDirectionalLight layout differs from the PDB");
