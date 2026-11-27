// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// TESForm, ActorProcess, Character, Actor::currentProcess, Character::sub_1407BCAF0: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorProcess::GetEquippedRightHand, ActorProcess::GetEquippedLeftHand, Character::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class TESForm;

class ActorProcess
{
public:
    TESForm* GetEquippedRightHand() const;
    TESForm* GetEquippedLeftHand() const;
};

class Character
{
public:
    bool sub_1407BCAF0() const;

    std::uint8_t  unk00[0xf8];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Character, currentProcess) == 0xf8, "Character::currentProcess offset");
