// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, ActorProcess::SetActorValueRegenDelay, HighProcessData: CRASHLOGGER_PDB(59818@2026.10.24)
// high, healthRegenDelay, staminaRegenDelay, magickaRegenDelay, gMaxHealthRegenDelay, gMaxStaminaRegenDelay, gMaxMagickaRegenDelay: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

extern float gMaxHealthRegenDelay;
extern float gMaxStaminaRegenDelay;
extern float gMaxMagickaRegenDelay;

struct HighProcessData
{
    std::uint8_t unk00[0x1C];
    float healthRegenDelay;
    float staminaRegenDelay;
    float magickaRegenDelay;
};

class ActorProcess
{
public:
    void SetActorValueRegenDelay(std::int32_t a_actorValue, float a_delay);

    std::uint8_t unk00[0x10];
    HighProcessData* high;
};

static_assert(offsetof(HighProcessData, healthRegenDelay) == 0x1C, "healthRegenDelay offset");
static_assert(offsetof(HighProcessData, staminaRegenDelay) == 0x20, "staminaRegenDelay offset");
static_assert(offsetof(HighProcessData, magickaRegenDelay) == 0x24, "magickaRegenDelay offset");
static_assert(offsetof(ActorProcess, high) == 0x10, "high offset");
