// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DESTRUCTIBLE_OBJECT_STAGE_FLAGS
#pragma once
enum class DESTRUCTIBLE_OBJECT_STAGE_FLAGS : int {
    kNone = 0,
    kCapDamage = 1,
    kDisableObject = 2,
    kDestroyObject = 4,
    kIgnoreExternalDamage = 8,
    kBecomesDynamic = 16,
};
