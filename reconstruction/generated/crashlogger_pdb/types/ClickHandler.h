// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ClickHandler; size 0x10
#pragma once

#include "MenuEventHandler.h"
struct ClickHandler {
    MenuEventHandler _base;
};
static_assert(sizeof(ClickHandler) == 16, "ClickHandler layout differs from the PDB");
