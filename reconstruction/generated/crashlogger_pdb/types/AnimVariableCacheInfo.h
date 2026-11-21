// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AnimVariableCacheInfo; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
struct hkbVariableValue;
struct AnimVariableCacheInfo {
    BSFixedString_char_83b572b4 variableName;
    hkbVariableValue* variable;
};
static_assert(sizeof(AnimVariableCacheInfo) == 16, "AnimVariableCacheInfo layout differs from the PDB");
