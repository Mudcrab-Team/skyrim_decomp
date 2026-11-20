// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CursorMenu; size 0x40
#pragma once

#include "IMenu_09c1ffe2.h"
#include "MenuEventHandler.h"
struct CursorMenu {
    IMenu_09c1ffe2 _base;
    MenuEventHandler _base_MenuEventHandler;
};
static_assert(sizeof(CursorMenu) == 64, "CursorMenu layout differs from the PDB");
