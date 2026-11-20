// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PLAYER_ACTION
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class PLAYER_ACTION : int {
    kNone = 0,
    kSwingMeleeWeapon = 1,
    kCastProjectileSpell = 2,
    kShootBow = 3,
    kZKeyObject = 4,
    kJumping = 5,
    kKnockingOverObjects = 6,
    kStandOnTableChair = 7,
    kIronSights = 8,
    kDestroyObject = 9,
    kLockedObject = 10,
    kPickpocket = 11,
    kCastSelfSpell = 12,
    kShout = 13,
    kActorCollision = 14,
    kTotal = 15,
    kInvalidMarker = 16,
};
