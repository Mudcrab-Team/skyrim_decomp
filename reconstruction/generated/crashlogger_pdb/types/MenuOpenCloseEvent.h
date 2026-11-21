// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuOpenCloseEvent; size 0x10
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct MenuOpenCloseEvent {
    BSFixedString_char_83b572b4 menuName;
    bool opening;
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int pad0C;
};
static_assert(sizeof(MenuOpenCloseEvent) == 16, "MenuOpenCloseEvent layout differs from the PDB");
