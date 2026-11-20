// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCharacterStateType
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class hkpCharacterStateType : int {
    kOnGround = 0,
    kJumping = 1,
    kInAir = 2,
    kClimbing = 3,
    kFlying = 4,
    kSwimming = 5,
    kUserState1 = 6,
    kUserState2 = 7,
    kUserState3 = 8,
    kUserState4 = 9,
    kUserState5 = 10,
    kTotal = 11,
};
