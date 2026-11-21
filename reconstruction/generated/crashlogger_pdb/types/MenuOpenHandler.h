// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuOpenHandler; size 0x18
#pragma once

#include "MenuEventHandler.h"
struct MenuOpenHandler {
    MenuEventHandler _base;
    bool unk10;
    unsigned char unk11;
    unsigned short unk12;
    unsigned int unk14;
};
static_assert(sizeof(MenuOpenHandler) == 24, "MenuOpenHandler layout differs from the PDB");
