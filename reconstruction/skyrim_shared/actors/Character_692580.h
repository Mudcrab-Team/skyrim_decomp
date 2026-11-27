// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, Character, Actor::currentProcess, Character::UpdateCachedValueData_1405ED420: CRASHLOGGER_PDB(59818@2026.10.24)
// CachedValuesData, ActorProcess::cachedValues, ActorProcess::unk00, Character::unk00, Character::ClearCachedFlag: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct CachedValuesData
{
    std::uint8_t  unk00[0x2c];
    std::uint32_t flags;  // 0x2c
};
static_assert(offsetof(CachedValuesData, flags) == 0x2c, "CachedValuesData::flags offset");

class ActorProcess
{
public:
    std::uint8_t      unk00[0x50];
    CachedValuesData* cachedValues;  // 0x50
};
static_assert(offsetof(ActorProcess, cachedValues) == 0x50, "ActorProcess::cachedValues offset");

class Character
{
public:
    void ClearCachedFlag(std::uint32_t a_mask)
    {
        if (currentProcess->cachedValues) {
            currentProcess->cachedValues->flags &= ~a_mask;
        }
    }

    void UpdateCachedValueData_1405ED420();

    std::uint8_t  unk00[0xf8];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Character, currentProcess) == 0xf8, "Character::currentProcess offset");
