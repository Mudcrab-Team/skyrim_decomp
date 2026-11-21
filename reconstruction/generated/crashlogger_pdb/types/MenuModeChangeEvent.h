// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuModeChangeEvent; size 0x10
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct MenuModeChangeEvent {
    BSFixedString_char_83b572b4 menu;
    unsigned char mode_raw[8];
};
static_assert(sizeof(MenuModeChangeEvent) == 16, "MenuModeChangeEvent layout differs from the PDB");
