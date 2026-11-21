// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCharacterStateInAir; size 0x18
#pragma once

#include "bhkCharacterState.h"
struct bhkCharacterStateInAir {
    bhkCharacterState _base;
    unsigned long long unk10;
};
static_assert(sizeof(bhkCharacterStateInAir) == 24, "bhkCharacterStateInAir layout differs from the PDB");
