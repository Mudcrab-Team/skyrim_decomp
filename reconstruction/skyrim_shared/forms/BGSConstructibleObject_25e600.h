// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// BGSConstructibleObject, BGSConstructibleObject::PlayerPassesConditions: CRASHLOGGER_PDB(59818@2026.10.24)
// ConditionNode25e600, PlayerCharacter25e600, TESCondition25e600: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class PlayerCharacter25e600
{
public:
    static PlayerCharacter25e600* singleton;
};

struct ConditionNode25e600;

struct TESCondition25e600
{
    ConditionNode25e600* head;  // 0x00

    bool IsTrue(PlayerCharacter25e600* a_actionRef, PlayerCharacter25e600* a_targetRef) const;
};

class BGSConstructibleObject
{
public:
    bool PlayerPassesConditions() const;

    std::uint8_t unk00[0x38];      // 0x00
    TESCondition25e600 conditions; // 0x38
};

static_assert(offsetof(BGSConstructibleObject, conditions) == 0x38, "conditions offset");
