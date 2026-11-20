// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRefCountWeakSupportImpl; size 0x18
#pragma once

#include "GRefCountNTSImpl.h"
struct GWeakPtrProxy;
struct GRefCountWeakSupportImpl {
    GRefCountNTSImpl _base;
    GWeakPtrProxy* weakProxy;
};
static_assert(sizeof(GRefCountWeakSupportImpl) == 24, "GRefCountWeakSupportImpl layout differs from the PDB");
