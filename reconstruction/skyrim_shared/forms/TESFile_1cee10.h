// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1cee10: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class TESFile
{
public:
    std::uint8_t unknown00[0x4a0];
    void* cached;
    void Build();

    void* Function1cee10();
};
