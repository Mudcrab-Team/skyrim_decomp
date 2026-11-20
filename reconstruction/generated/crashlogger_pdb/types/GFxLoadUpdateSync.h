// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxLoadUpdateSync; size 0x48
#pragma once

#include "GMutex.h"
#include "GRefCountBase_RE__GFxLoadUpdateSync_265_fca221b8.h"
struct GFxLoadUpdateSync {
    GRefCountBase_RE__GFxLoadUpdateSync_265_fca221b8 _base;
    GMutex mutex;
    void* unk38;
    void* unk40;
};
static_assert(sizeof(GFxLoadUpdateSync) == 72, "GFxLoadUpdateSync layout differs from the PDB");
