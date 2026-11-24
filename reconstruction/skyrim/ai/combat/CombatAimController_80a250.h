// Source exposure: mixed (CrashLogger layout names; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// CombatAimController, P, flags, timer, AITimer, AITimer::aiTimer, AITimer::timer, NiPoint3: CRASHLOGGER_PDB(59818@2026.10.24)
// CombatAimController::Function80a250, unk00, unk24, gUnk324430c, kFlagUnk0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

extern float gUnk324430c;  // data at 0x324430c

struct AITimer
{
    AITimer(float a_aiTimer, float a_timer) : aiTimer(a_aiTimer), timer(a_timer) {}

    float aiTimer;
    float timer;
};

// FlagSet, FlagSet::set, FlagSet::value: GUESS(low); stand-in for the PDB flags enumeration type
struct FlagSet
{
    void set(std::uint32_t a_flag) { value |= a_flag; }

    std::uint32_t value;
};

class CombatAimController
{
public:
    void Function80a250(const NiPoint3& a_point);  // compared: 0x80a250

    std::uint8_t unk00[0x18];
    NiPoint3 P;
    std::uint8_t unk24[0x18];
    FlagSet flags;
    AITimer timer;
};
static_assert(offsetof(CombatAimController, flags) == 0x3C, "CombatAimController::flags offset");
static_assert(sizeof(CombatAimController) == 0x48, "CombatAimController size");
