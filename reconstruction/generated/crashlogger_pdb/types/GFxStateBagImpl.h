// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxStateBagImpl; size 0x60
#pragma once

#include "GFxLogBase_RE__GFxStateBagImpl_e25097b2.h"
#include "GFxStateBag.h"
#include "GRefCountBase_RE__GFxStateBagImpl_2_5b15bd40.h"
struct GFxStateBagImpl {
    GRefCountBase_RE__GFxStateBagImpl_2_5b15bd40 _base;
    GFxStateBag _base_GFxStateBag;
    unsigned char undefined_18[8];
    GFxLogBase_RE__GFxStateBagImpl_e25097b2 _base_GFxLogBase_RE_GFxStateBagImpl_;
    unsigned long long unk28[7];
};
static_assert(sizeof(GFxStateBagImpl) == 96, "GFxStateBagImpl layout differs from the PDB");
