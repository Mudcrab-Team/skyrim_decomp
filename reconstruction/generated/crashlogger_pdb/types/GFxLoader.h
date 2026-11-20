// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxLoader; size 0x20
#pragma once

#include "GFxStateBag.h"
#include "GPtr_RE__GFxLoaderImpl_2e1ac7de.h"
#include "GPtr_RE__GFxResourceLib_80996013.h"
struct GFxLoader {
    GFxStateBag _base;
    GPtr_RE__GFxLoaderImpl_2e1ac7de impl;
    GPtr_RE__GFxResourceLib_80996013 strongResourceLib;
    unsigned int defLoadFlags;
    unsigned int pad1C;
};
static_assert(sizeof(GFxLoader) == 32, "GFxLoader layout differs from the PDB");
