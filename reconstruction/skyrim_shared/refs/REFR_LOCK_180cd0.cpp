// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// REFR_LOCK, REFR_LOCK::GetLevel: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x180cd0 REFR_LOCK::GetLevel
#include "REFR_LOCK_180cd0.h"

// Computes the effective lock level, scaling by owner or player level when leveled.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
std::int32_t REFR_LOCK::GetLevel(TESObjectREFR* a_owner)
{
    std::int32_t level = baseLevel;
    if (baseLevel != gLockMaxLevel && (flags & 0x04) != 0)
    {
        std::int32_t ownerLevel = a_owner ? a_owner->GetCalcLevel(false) : gPlayerCharacter->GetLevel();
        level += ownerLevel * static_cast<std::int32_t>(gLockLevelMult);
        if (level > 99)
        {
            level = 99;
        }
    }
    return level;
}
