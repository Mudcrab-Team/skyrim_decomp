// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ModManagerMenu; size 0x58
#pragma once

#include "GFxFunctionHandler.h"
#include "IMenu_09c1ffe2.h"
#include "MenuEventHandler.h"
struct ModManagerMenu {
    IMenu_09c1ffe2 _base;
    MenuEventHandler _base_MenuEventHandler;
    GFxFunctionHandler _base_GFxFunctionHandler;
    bool useTransparentBackground;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(ModManagerMenu) == 88, "ModManagerMenu layout differs from the PDB");
