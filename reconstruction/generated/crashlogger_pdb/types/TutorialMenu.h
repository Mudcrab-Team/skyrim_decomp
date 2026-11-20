// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TutorialMenu; size 0x48
#pragma once

#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct TutorialMenu {
    IMenu_09c1ffe2 _base;
    GFxValue root;
};
static_assert(sizeof(TutorialMenu) == 72, "TutorialMenu layout differs from the PDB");
