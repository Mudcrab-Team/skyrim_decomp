// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// NiPoint3, ActorProcess, Actor, Actor::currentProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// Actor::GetLinearVelocity_1405D3EB0: CRASHLOGGER_PDB(59818@2026.10.24)
// VelocityController, VelocityController::linearVelocity, ActorProcess::GetVelocityController, kNiPointZero: GUESS(low)
// VelocityController::unk00, Actor::unk00: GUESS(low); unresolved bytes before represented members
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

class VelocityController
{
public:
    std::uint8_t unk00[0x180];
    NiPoint3     linearVelocity;  // 0x180
};
static_assert(offsetof(VelocityController, linearVelocity) == 0x180, "VelocityController::linearVelocity offset");

class ActorProcess
{
public:
    VelocityController* GetVelocityController() const;
};

class Actor
{
public:
    void GetLinearVelocity_1405D3EB0(NiPoint3& a_out) const;

    std::uint8_t  unk00[0xf8];
    ActorProcess* currentProcess;  // 0xf8
};
static_assert(offsetof(Actor, currentProcess) == 0xf8, "Actor::currentProcess offset");
