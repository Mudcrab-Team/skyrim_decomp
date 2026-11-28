// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ActorValueMeter, ActorValueMeter::GetFillPercent: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x937dc0 ActorValueMeter::GetFillPercent
#include "ActorValueMeter_937dc0.h"

// Computes the player actor value fill percentage from current and effective max values.
float ActorValueMeter::GetFillPercent()
{
    float current = gPlayerCharacter->avOwner.GetActorValue(actorValue);
    if (current < 0.0f)
    {
        current = 0.0f;
    }

    PlayerCharacter* player = gPlayerCharacter;
    float base = player->avOwner.GetActorValue(actorValue);
    float mod = player->GetActorValueModifier(2, actorValue);
    float maxVal = base - mod;
    if (maxVal != 0.0f)
    {
        return (current / maxVal) * 100.0f;
    }
    return 0.0f;
}
