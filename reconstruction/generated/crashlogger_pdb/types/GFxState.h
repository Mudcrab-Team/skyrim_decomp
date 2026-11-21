// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxState; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "GRefCountBase_RE__GFxState_2_6cec4dcf.h"
#include "StateType.h"
struct GFxState {
    GRefCountBase_RE__GFxState_2_6cec4dcf _base;
    StateType stateType;
    unsigned int pad14;
};
static_assert(sizeof(GFxState) == 24, "GFxState layout differs from the PDB");
