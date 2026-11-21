// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FavoritesHandler; size 0x10
#pragma once

#include "MenuEventHandler.h"
struct FavoritesHandler {
    MenuEventHandler _base;
};
static_assert(sizeof(FavoritesHandler) == 16, "FavoritesHandler layout differs from the PDB");
