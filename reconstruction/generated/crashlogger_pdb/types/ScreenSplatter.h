// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ScreenSplatter; size 0x40
#pragma once

#include "BSTSingletonSDM_RE__ScreenSplatter_83b55007.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
struct ScreenSplatter {
    BSTSingletonSDM_RE__ScreenSplatter_83b55007 _base;
    unsigned char pad01;
    unsigned short pad02;
    unsigned int pad04;
    NiPointer_RE__NiNode_28171d5b root;
    NiPointer_RE__NiCamera_cf3a8333 camera;
    float wRadius;
    float hRadius;
    bool enabled;
    bool pad21;
    unsigned short pad22;
    unsigned int uiCount;
    unsigned char textures_raw[24];
};
static_assert(sizeof(ScreenSplatter) == 64, "ScreenSplatter layout differs from the PDB");
