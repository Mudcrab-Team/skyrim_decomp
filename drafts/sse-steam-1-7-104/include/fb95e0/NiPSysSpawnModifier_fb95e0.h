// Exposure detail: (pinned-image observations; community-generated names).
// Source exposure: mixed
// Code origin: original; partial declarations from labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// NiPSysSpawnModifier, NiPSysSpawnModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiPSysModifier, NiPSysModifier::IsEqual: STANDIN OBSERVED
// unknown00, generations, percentage, minimum, maximum, speedChaos, directionChaos, lifeSpan, lifeSpanVariance: STANDIN GUESS(low); descriptive fields at observed offsets

#pragma once
#include <cstdint>
class NiObject {};
class NiPSysModifier : public NiObject
{
public:
    bool IsEqual(NiObject* object);
    std::uint8_t unknown00[0x30];
};
class NiPSysSpawnModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* object);
    std::uint16_t generations;
    float percentage;
    std::uint16_t minimum;
    std::uint16_t maximum;
    float speedChaos;
    float directionChaos;
    float lifeSpan;
    float lifeSpanVariance;
};
static_assert(sizeof(NiPSysModifier) == 0x30, "Observed modifier base extent");
