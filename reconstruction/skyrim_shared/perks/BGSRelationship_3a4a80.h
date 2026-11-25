// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSRelationship: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function3a4a80: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class BGSRelationship
{
public:
    std::uint8_t unknown00[0x38];
    std::uint32_t packedLevel;

    std::uint32_t Function3a4a80();
};
