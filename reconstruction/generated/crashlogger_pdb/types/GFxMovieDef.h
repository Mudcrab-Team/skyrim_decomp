// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxMovieDef; size 0x20
#pragma once

#include "GFxResource.h"
#include "GFxStateBag.h"
struct GFxMovieDef {
    GFxResource _base;
    GFxStateBag _base_GFxStateBag;
};
static_assert(sizeof(GFxMovieDef) == 32, "GFxMovieDef layout differs from the PDB");
