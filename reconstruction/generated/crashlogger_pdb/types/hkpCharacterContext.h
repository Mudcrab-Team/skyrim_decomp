// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCharacterContext; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "CharacterType.h"
#include "hkpCharacterStateType_dce6b736.h"
struct hkpCharacterStateManager;
struct hkpCharacterContext {
    unsigned char undefined_0[8];
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    unsigned char undefined_c[4];
    CharacterType characterType;
    unsigned char undefined_14[4];
    hkpCharacterStateManager* m_stateManager_18;
    hkpCharacterStateType_dce6b736 currentState;
    hkpCharacterStateType_dce6b736 previousState;
    bool filterEnable;
    unsigned char pad29;
    unsigned short pad2A;
    float m_maxLinearAcceleration_2C;
    float m_maxLinearVelocity_30;
    float m_gain_34;
};
static_assert(sizeof(hkpCharacterContext) == 56, "hkpCharacterContext layout differs from the PDB");
