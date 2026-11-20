// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GWaitable; size 0x18
#pragma once

#include "GRefCountBase_RE__GWaitable_2_04337cf8.h"
struct HandlerArray;
struct GWaitable {
    GRefCountBase_RE__GWaitable_2_04337cf8 _base;
    HandlerArray* handlers;
};
static_assert(sizeof(GWaitable) == 24, "GWaitable layout differs from the PDB");
