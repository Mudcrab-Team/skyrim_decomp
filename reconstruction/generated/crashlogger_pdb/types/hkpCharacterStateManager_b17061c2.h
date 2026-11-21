// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCharacterStateManager; size 0x68
// one of 2 different PDB types sharing this name
#pragma once

#include "hkReferencedObject.h"
struct hkpCharacterState_70fd485c;
struct hkpCharacterStateManager_b17061c2 {
    hkReferencedObject _base;
    hkpCharacterState_70fd485c* registeredState[11];
};
static_assert(sizeof(hkpCharacterStateManager_b17061c2) == 104, "hkpCharacterStateManager_b17061c2 layout differs from the PDB");
