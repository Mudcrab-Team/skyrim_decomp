// Source exposure: binary-analysis (pinned image).
// Code origin: original partial layout assembled from the compared field accesses.
// NiPSysAirFieldModifierFields: STANDIN GUESS(low)
// airFriction, inheritVelocity, spread: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

namespace ResearchLayouts
{
struct NiPSysAirFieldModifierFields
{
    std::uint8_t padding00[0x78];
    float airFriction;
    float inheritVelocity;
    std::uint8_t padding80[0x4];
    float spread;
};
static_assert(offsetof(NiPSysAirFieldModifierFields, airFriction) == 0x78, "airFriction offset");
static_assert(offsetof(NiPSysAirFieldModifierFields, inheritVelocity) == 0x7C, "inheritVelocity offset");
static_assert(offsetof(NiPSysAirFieldModifierFields, spread) == 0x84, "spread offset");
}
