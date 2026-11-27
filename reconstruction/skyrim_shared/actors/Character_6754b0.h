// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// Character, Character::sub_1405D2330, Actor::boolBits, Actor::voiceTimer: CRASHLOGGER_PDB(59818@2026.10.24)
// Character::unk00, Character::unkEC: GUESS(low); unresolved bytes before represented members
#pragma once

#include <cstddef>
#include <cstdint>

class Character
{
public:
    bool sub_1405D2330() const;

    std::uint8_t  unk00[0xe8];
    std::uint32_t boolBits;    // 0xe8
    std::uint8_t  unkEC[0x24];
    float         voiceTimer;  // 0x110
};
static_assert(offsetof(Character, boolBits) == 0xe8, "Character::boolBits offset");
static_assert(offsetof(Character, voiceTimer) == 0x110, "Character::voiceTimer offset");
