// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRefCountBaseGC<323>; size 0x20
#pragma once

#include "GNewOverrideBase_323_7f544416.h"
struct GRefCountBaseGC_vtbl;
struct GRefCountBaseGC_323_a76058cc {
    GRefCountBaseGC_vtbl* __vftable;
    GNewOverrideBase_323_7f544416 _base_GNewOverrideBase_323_;
    unsigned char undefined_9[7];
    unsigned int refCount;
    unsigned int pad14;
    unsigned long long unk18;
};
static_assert(sizeof(GRefCountBaseGC_323_a76058cc) == 32, "GRefCountBaseGC_323_a76058cc layout differs from the PDB");
