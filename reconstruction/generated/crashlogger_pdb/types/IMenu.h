// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMenu; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "FxDelegateHandler.h"
#include "GPtr_RE__FxDelegate_01e32d06.h"
#include "GPtr_RE__GFxMovieView_2d8822bd.h"
#include "INPUT_CONTEXT_ID_65e8d7b4.h"
#include "UI_MENU_FLAGS_a60ab300.h"
#include "UI_MENU_Unk09.h"
struct IMenu {
    FxDelegateHandler _base;
    GPtr_RE__GFxMovieView_2d8822bd uiMovie;
    unsigned char depthPriority;
    unsigned char pad19;
    unsigned short pad20;
    UI_MENU_FLAGS_a60ab300 menuFlags;
    INPUT_CONTEXT_ID_65e8d7b4 inputContext;
    unsigned int pad24;
    GPtr_RE__FxDelegate_01e32d06 fxDelegate;
    UI_MENU_Unk09 unk30;
    unsigned char unk34;
    unsigned char undefined_35[3];
    BSFixedString_char_83b572b4 menuName;
};
static_assert(sizeof(IMenu) == 64, "IMenu layout differs from the PDB");
