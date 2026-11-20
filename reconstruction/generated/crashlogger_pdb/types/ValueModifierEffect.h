// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ValueModifierEffect; size 0x98
#pragma once

#include "ActiveEffect_7b2473e9.h"
#include "ActorValue.h"
struct ValueModifierEffect {
    ActiveEffect_7b2473e9 _base;
    ActorValue actorValue;
    float value;
};
static_assert(sizeof(ValueModifierEffect) == 152, "ValueModifierEffect layout differs from the PDB");
