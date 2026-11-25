// Source exposure: mixed (community declarations; local target observations).
// Code origin: original; local target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysEmitter, NiPSysEmitter::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include "NiPSysModifier.h"
#include <cstddef>

class NiPSysEmitter : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* object) override;
    // unknown30, speed, speedVariance, declination, declinationVariance, planarAngle, planarAngleVariance, initialColor, initialRadius, radiusVariance, lifeSpan, lifeSpanVariance: GUESS(low)
    std::uint32_t unknown30;
    float speed;
    float speedVariance;
    float declination;
    float declinationVariance;
    float planarAngle;
    float planarAngleVariance;
    float initialColor[4];
    float initialRadius;
    float radiusVariance;
    float lifeSpan;
    float lifeSpanVariance;
};
static_assert(offsetof(NiPSysEmitter, speed) == 0x34, "speed offset");
static_assert(offsetof(NiPSysEmitter, initialColor) == 0x4C, "color offset");
static_assert(offsetof(NiPSysEmitter, lifeSpanVariance) == 0x68, "life variance offset");
