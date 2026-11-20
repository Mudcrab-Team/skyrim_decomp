// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InGameFormFlag
#pragma once
enum class InGameFormFlag : int {
    kNone = 0,
    kWantsDelete = 1,
    kForcedPersistent = 2,
    kNoFavorAllowed = 16,
    kIsSkyObject = 32,
    kRefOriginalPersistent = 64,
    kRefPermanentlyDeleted = 128,
};
