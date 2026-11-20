// Source exposure: binary-analysis (pinned image).
// Code origin: original partial layout assembled from the compared field accesses.
// NiPSysRotationModifierFields: STANDIN GUESS(low)
// initialRotationSpeed, initialRotationSpeedVariance, initialRotationAngle, initialRotationAngleVariance: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

namespace ResearchLayouts
{
struct NiPSysRotationModifierFields
{
    std::uint8_t padding00[0x30];
    float initialRotationSpeed;
    float initialRotationSpeedVariance;
    float initialRotationAngle;
    float initialRotationAngleVariance;
};
static_assert(offsetof(NiPSysRotationModifierFields, initialRotationSpeed) == 0x30, "initialRotationSpeed offset");
static_assert(offsetof(NiPSysRotationModifierFields, initialRotationSpeedVariance) == 0x34, "initialRotationSpeedVariance offset");
static_assert(offsetof(NiPSysRotationModifierFields, initialRotationAngle) == 0x38, "initialRotationAngle offset");
static_assert(offsetof(NiPSysRotationModifierFields, initialRotationAngleVariance) == 0x3C, "initialRotationAngleVariance offset");
}
