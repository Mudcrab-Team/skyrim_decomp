// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UnkData; size 0x10
#pragma once

#include "State_675e5871.h"
struct BSEffectShaderProperty;
struct UnkData {
    BSEffectShaderProperty* unk00;
    State_675e5871 state;
    unsigned int unk0C;
};
static_assert(sizeof(UnkData) == 16, "UnkData layout differs from the PDB");
