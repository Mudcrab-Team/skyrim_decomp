// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QuickSaveLoadHandler; size 0x10
#pragma once

#include "MenuEventHandler.h"
struct QuickSaveLoadHandler {
    MenuEventHandler _base;
};
static_assert(sizeof(QuickSaveLoadHandler) == 16, "QuickSaveLoadHandler layout differs from the PDB");
