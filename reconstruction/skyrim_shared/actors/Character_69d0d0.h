// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, Character, Actor::currentProcess, Character::sub_1405F7730: CRASHLOGGER_PDB(59818@2026.10.24)
// ProcessSub69d0d0, ActorProcess::GetSub6ff530, ActorProcess::Finish6f6f80, kDefaultTimer69d0d0, Character::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern const float kDefaultTimer69d0d0;

struct ProcessSub69d0d0
{
    std::uint8_t  unk00[0x18];
    std::uint32_t unk18;  // 0x18
    float         unk1c;  // 0x1c
};
static_assert(offsetof(ProcessSub69d0d0, unk18) == 0x18, "ProcessSub69d0d0::unk18 offset");
static_assert(offsetof(ProcessSub69d0d0, unk1c) == 0x1c, "ProcessSub69d0d0::unk1c offset");

class ActorProcess
{
public:
    ProcessSub69d0d0* GetSub6ff530();
    void              Finish6f6f80();
};

class Character
{
public:
    void sub_1405F7730();

    std::uint8_t  unk00[0xf8];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Character, currentProcess) == 0xf8, "Character::currentProcess offset");
