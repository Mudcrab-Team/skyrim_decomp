// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HUDObject; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "GFxValue.h"
#include "GPtr_RE__GFxMovieView_2d8822bd.h"
struct HUDObject_vtbl;
struct HUDObject {
    HUDObject_vtbl* __vftable;
    GPtr_RE__GFxMovieView_2d8822bd view;
    GFxValue root;
};
static_assert(sizeof(HUDObject) == 40, "HUDObject layout differs from the PDB");
