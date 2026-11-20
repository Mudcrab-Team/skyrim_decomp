// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxState; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "GRefCountBase_RE__GFxState_2_6cec4dcf_7a0a042e.h"
#include "StateType.h"
struct GFxState_6a94ada2 {
    GRefCountBase_RE__GFxState_2_6cec4dcf_7a0a042e _base;
    StateType stateType;
    unsigned int pad14;
};
static_assert(sizeof(GFxState_6a94ada2) == 24, "GFxState_6a94ada2 layout differs from the PDB");
