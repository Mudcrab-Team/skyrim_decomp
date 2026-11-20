// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxResource; size 0x18
#pragma once

#include "GNewOverrideBase_2_e860072d.h"
struct GFxResourceLibBase;
struct GFxResource_vtbl;
struct GFxResource {
    GFxResource_vtbl* __vftable;
    GNewOverrideBase_2_e860072d _base_GNewOverrideBase_2_;
    unsigned char undefined_9[3];
    unsigned int _pad0C;
    GFxResourceLibBase* _lib;
};
static_assert(sizeof(GFxResource) == 24, "GFxResource layout differs from the PDB");
