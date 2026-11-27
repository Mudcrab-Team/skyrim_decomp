// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSParticleShaderProperty: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function15336e0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Geometry15336e0: GUESS(low) STANDIN; geometry element count
struct Geometry15336e0 { std::uint8_t unknown00[0x1a]; std::uint16_t count; };

class BSParticleShaderProperty
{
public:
    std::uint8_t unknown00[0x150];
    Geometry15336e0** geometries;
    std::uint64_t unknown158;
    unsigned count;

    unsigned Function15336e0();
};
