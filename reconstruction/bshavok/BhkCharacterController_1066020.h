// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original partial layout from the velocity modifier entry.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BhkCharacterController: STANDIN EXE_RTTI
// outVelocity, initialVelocity, flags, velocityTime: OBSERVED
// ApplyInitialVelocity: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class BhkCharacterController
{
public:
    void ApplyInitialVelocity();

private:
    std::uint8_t unknown00[0x90];
    alignas(16) __m128 outVelocity;
    alignas(16) __m128 initialVelocity;
    std::uint8_t unknownB0[0x168];
    std::uint32_t flags;
    std::uint32_t unknown21C;
    float velocityTime;
};
