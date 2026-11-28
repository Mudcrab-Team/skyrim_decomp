// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, ActorProcess::SetActorValueRegenDelay: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x7001c0 ActorProcess::SetActorValueRegenDelay
#include "ActorProcess_7001c0.h"

// Sets the actor value regeneration delay, clamped to the attribute maximum.
void ActorProcess::SetActorValueRegenDelay(std::int32_t a_actorValue, float a_delay)
{
    HighProcessData* data = high;
    if (data == nullptr)
    {
        return;
    }

    switch (a_actorValue)
    {
    case 0x18:
        if (a_delay == 0.0f || a_delay > data->healthRegenDelay)
        {
            data->healthRegenDelay = (a_delay < gMaxHealthRegenDelay) ? a_delay : gMaxHealthRegenDelay;
        }
        break;
    case 0x19:
        if (a_delay == 0.0f || a_delay > data->magickaRegenDelay)
        {
            data->magickaRegenDelay = (a_delay < gMaxMagickaRegenDelay) ? a_delay : gMaxMagickaRegenDelay;
        }
        break;
    case 0x1A:
        if (a_delay == 0.0f || a_delay > data->staminaRegenDelay)
        {
            data->staminaRegenDelay = (a_delay < gMaxStaminaRegenDelay) ? a_delay : gMaxStaminaRegenDelay;
        }
        break;
    default:
        break;
    }
}
