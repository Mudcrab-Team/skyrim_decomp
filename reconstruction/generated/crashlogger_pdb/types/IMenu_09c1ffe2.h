// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMenu; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "FxDelegateHandler_ccd4e5d3.h"
#include "GPtr_RE__FxDelegate_01e32d06.h"
#include "GPtr_RE__GFxMovieView_2d8822bd.h"
#include "INPUT_CONTEXT_ID.h"
#include "UI_MENU_FLAGS.h"
struct IMenu_09c1ffe2 {
    FxDelegateHandler_ccd4e5d3 _base;
    GPtr_RE__GFxMovieView_2d8822bd uiMovie;
    unsigned char depthPriority;
    unsigned char pad19;
    unsigned short pad20;
    UI_MENU_FLAGS menuFlags;
    INPUT_CONTEXT_ID inputContext;
    unsigned int pad24;
    GPtr_RE__FxDelegate_01e32d06 fxDelegate;
};
static_assert(sizeof(IMenu_09c1ffe2) == 48, "IMenu_09c1ffe2 layout differs from the PDB");
