// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCharacterContext; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "CharacterType.h"
#include "hkReferencedObject.h"
#include "hkpCharacterStateType.h"
struct hkpCharacterStateManager_b17061c2;
struct hkpCharacterContext_47f0195b {
    hkReferencedObject _base;
    CharacterType characterType;
    unsigned int pad14;
    hkpCharacterStateManager_b17061c2* stateManager;
    hkpCharacterStateType currentState;
    hkpCharacterStateType previousState;
    bool filterEnable;
    unsigned char pad29;
    unsigned short pad2A;
    float maxLinearAcceleration;
    float maxLinearVelocity;
    float gain;
};
static_assert(sizeof(hkpCharacterContext_47f0195b) == 56, "hkpCharacterContext_47f0195b layout differs from the PDB");
