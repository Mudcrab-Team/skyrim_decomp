// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// REFR_LOCK, REFR_LOCK::GetLevel, REFR_LOCK::baseLevel, REFR_LOCK::flags: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectREFR, PlayerCharacter: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectREFR::GetCalcLevel, PlayerCharacter::GetLevel, gLockMaxLevel, gLockLevelMult, gPlayerCharacter: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class TESObjectREFR
{
public:
    std::uint16_t GetCalcLevel(bool a_adjust);
};

class PlayerCharacter
{
public:
    std::uint16_t GetLevel();
};

extern std::uint8_t gLockMaxLevel;
extern float gLockLevelMult;
extern PlayerCharacter* gPlayerCharacter;

struct REFR_LOCK
{
    std::int32_t GetLevel(TESObjectREFR* a_owner);

    std::uint8_t baseLevel;
    std::uint8_t unk01[0x0F];
    std::uint8_t flags;
};

static_assert(offsetof(REFR_LOCK, baseLevel) == 0x00, "baseLevel offset");
static_assert(offsetof(REFR_LOCK, flags) == 0x10, "flags offset");
