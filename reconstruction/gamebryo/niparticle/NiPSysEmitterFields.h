// Source exposure: binary-analysis (pinned image).
// Code origin: original partial layout assembled from the compared field accesses.
// NiPSysEmitterFields: STANDIN GUESS(low)
// speed, declination, declinationVariance, planarAngle, planarAngleVariance, initialRadius, lifeSpan: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

namespace ResearchLayouts
{
struct NiPSysEmitterFields
{
    std::uint8_t padding00[0x34];
    float speed;
    std::uint8_t padding38[0x4];
    float declination;
    float declinationVariance;
    float planarAngle;
    float planarAngleVariance;
    std::uint8_t padding4C[0x10];
    float initialRadius;
    std::uint8_t padding60[0x4];
    float lifeSpan;
};
static_assert(offsetof(NiPSysEmitterFields, speed) == 0x34, "speed offset");
static_assert(offsetof(NiPSysEmitterFields, declination) == 0x3C, "declination offset");
static_assert(offsetof(NiPSysEmitterFields, declinationVariance) == 0x40, "declinationVariance offset");
static_assert(offsetof(NiPSysEmitterFields, planarAngle) == 0x44, "planarAngle offset");
static_assert(offsetof(NiPSysEmitterFields, planarAngleVariance) == 0x48, "planarAngleVariance offset");
static_assert(offsetof(NiPSysEmitterFields, initialRadius) == 0x5C, "initialRadius offset");
static_assert(offsetof(NiPSysEmitterFields, lifeSpan) == 0x64, "lifeSpan offset");
}
