// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxResourceLib; size 0x28
#pragma once

#include "GHashSet_RE__GFxResource_RE__GFxResourceLib__GFxResourcePtrHashFunc_b9e60b00.h"
#include "GRefCountBase_RE__GFxResourceLib_2_69517fa5.h"
struct GFxResourceWeakLib;
struct GFxResourceLib {
    GRefCountBase_RE__GFxResourceLib_2_69517fa5 _base;
    GFxResourceWeakLib* weakLib;
    GHashSet_RE__GFxResource_RE__GFxResourceLib__GFxResourcePtrHashFunc_b9e60b00 pinSet;
    bool debugFlag;
    unsigned char pad21;
    unsigned short pad22;
    unsigned int pad24;
};
static_assert(sizeof(GFxResourceLib) == 40, "GFxResourceLib layout differs from the PDB");
