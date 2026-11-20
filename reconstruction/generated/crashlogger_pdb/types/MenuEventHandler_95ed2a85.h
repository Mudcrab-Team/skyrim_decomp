// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuEventHandler; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "BSIntrusiveRefCounted_8d4cb673.h"
struct MenuEventHandler__VFTable;
struct MenuEventHandler_95ed2a85 {
    MenuEventHandler__VFTable* vftable_MenuEventHandler_0;
    BSIntrusiveRefCounted_8d4cb673 _base_BSIntrusiveRefCounted;
    bool Registered_C;
    unsigned char unk0D;
    unsigned short pad0E;
};
static_assert(sizeof(MenuEventHandler_95ed2a85) == 16, "MenuEventHandler_95ed2a85 layout differs from the PDB");
