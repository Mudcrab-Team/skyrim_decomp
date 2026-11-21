// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCharacterStateManager; size 0x68
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpCharacterState;
struct hkpCharacterStateManager__VFTable;
struct hkpCharacterStateManager {
    hkpCharacterStateManager__VFTable* vftable_hkpCharacterStateManager_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpCharacterState* m_registeredState_10[11];
};
static_assert(sizeof(hkpCharacterStateManager) == 104, "hkpCharacterStateManager layout differs from the PDB");
