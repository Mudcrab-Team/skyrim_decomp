// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSTextureSet: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function32d700: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Texture32d700: GUESS(low) STANDIN; texture subobject whose contents are unused
struct Texture32d700 { std::uint64_t unknown00; };

class BGSTextureSet
{
public:
    std::uint8_t unknown00[0x30];
    Texture32d700 texture;

    Texture32d700* Function32d700();
};
