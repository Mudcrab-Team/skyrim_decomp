// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original declarations from observed parameter use
// SPDX-License-Identifier: CC0-1.0
// TESBoundObject, TESBoundObject::GetTemperedValue: CRASHLOGGER_PDB(59818@2026.10.24)
// TemperSetting, temperScalingEnabled, temperScalingSetting, temperBaseline: STANDIN GUESS(low)
#pragma once
#include <cstdint>

struct TemperSetting
{
    std::uint8_t prefix00[8];
    float value;
};
extern void* temperScalingEnabled;
extern const float temperBaseline;
extern TemperSetting* temperScalingSetting;
class TESBoundObject
{
public:
    static float GetTemperedValue(float value, float health);
};
