// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCharacterStateOnGround; size 0x18
#pragma once

#include "bhkCharacterState.h"
struct bhkCharacterStateOnGround {
    bhkCharacterState _base;
    unsigned long long unk10;
};
static_assert(sizeof(bhkCharacterStateOnGround) == 24, "bhkCharacterStateOnGround layout differs from the PDB");
