// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxStream: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond456b0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class GFxStream
{
public:
    std::uint8_t unknown00[0x4c];
    int base;
    int position;
    int end;
    int Tell();

    std::int64_t Functiond456b0();
};
