// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuEventHandler; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted.h"
struct MenuEventHandler_vtbl;
struct MenuEventHandler {
    MenuEventHandler_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    bool registered;
    unsigned char unk0D;
    unsigned short pad0E;
};
static_assert(sizeof(MenuEventHandler) == 16, "MenuEventHandler layout differs from the PDB");
