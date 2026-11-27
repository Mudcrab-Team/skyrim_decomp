// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// NiPoint3, ActorProcess, Actor, Actor::currentProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// Actor::Func282_14060AA70: CRASHLOGGER_PDB(59818@2026.10.24)
// CharController282, ActorProcess::GetController, kNiPointZero: GUESS(low)
// CharController282::unk00, CharController282::unk314, CharController282::unk318, CharController282::unk31d, Actor::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

extern const NiPoint3 kNiPointZero;

class CharController282
{
public:
    std::uint8_t  unk00[0x314];
    std::uint32_t unk314;  // 0x314
    std::uint8_t  unk318[0x5];
    std::uint8_t  unk31d;  // 0x31d
};
static_assert(offsetof(CharController282, unk314) == 0x314, "CharController282::unk314 offset");
static_assert(offsetof(CharController282, unk31d) == 0x31d, "CharController282::unk31d offset");

class ActorProcess
{
public:
    CharController282* GetController() const;
};

class Actor
{
public:
    void Func282_14060AA70(std::uint64_t a_unused, NiPoint3& a_out) const;

    std::uint8_t  unk00[0xf8];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, currentProcess) == 0xf8, "Actor::currentProcess offset");
