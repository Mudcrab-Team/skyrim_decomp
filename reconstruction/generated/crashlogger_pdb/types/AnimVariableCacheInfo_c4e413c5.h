// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AnimVariableCacheInfo; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

struct hkbVariableValue;
struct AnimVariableCacheInfo_c4e413c5 {
    unsigned char variableName_raw[8];
    hkbVariableValue* variable;
};
static_assert(sizeof(AnimVariableCacheInfo_c4e413c5) == 16, "AnimVariableCacheInfo_c4e413c5 layout differs from the PDB");
