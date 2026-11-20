// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SprintHandler; size 0x18
#pragma once

#include "HeldStateHandler.h"
struct SprintHandler {
    HeldStateHandler _base;
};
static_assert(sizeof(SprintHandler) == 24, "SprintHandler layout differs from the PDB");
