// Source exposure: binary-analysis (pinned image).
// Code origin: original partial layout assembled from the compared field accesses.
// NiPSysFieldModifierFields: STANDIN GUESS(low)
// magnitude, attenuation, maxDistance, maxDistanceSquared: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

namespace ResearchLayouts
{
struct NiPSysFieldModifierFields
{
    std::uint8_t padding00[0x38];
    float magnitude;
    float attenuation;
    std::uint8_t padding40[0x4];
    float maxDistance;
    float maxDistanceSquared;
};
static_assert(offsetof(NiPSysFieldModifierFields, magnitude) == 0x38, "magnitude offset");
static_assert(offsetof(NiPSysFieldModifierFields, attenuation) == 0x3C, "attenuation offset");
static_assert(offsetof(NiPSysFieldModifierFields, maxDistance) == 0x44, "maxDistance offset");
static_assert(offsetof(NiPSysFieldModifierFields, maxDistanceSquared) == 0x48, "maxDistanceSquared offset");
}
