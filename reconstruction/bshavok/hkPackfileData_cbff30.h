// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkPackfileData: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioncbff30: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class hkPackfileData
{
public:
    std::uint8_t unknown00[0x38];
    unsigned count;

    int Functioncbff30();
};
