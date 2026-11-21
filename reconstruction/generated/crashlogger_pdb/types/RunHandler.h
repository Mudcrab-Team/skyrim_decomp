// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RunHandler; size 0x18
#pragma once

#include "HeldStateHandler.h"
struct RunHandler {
    HeldStateHandler _base;
};
static_assert(sizeof(RunHandler) == 24, "RunHandler layout differs from the PDB");
