// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegion: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function24f9e0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Point24f9e0, Link24f9e0, regionBound24f9e0: GUESS(low) STANDIN; region boundary points
struct Point24f9e0 { float Get(); };
struct Link24f9e0 { Point24f9e0* point; Link24f9e0* next; };
extern float regionBound24f9e0;

class TESRegion
{
public:
    std::uint8_t unknown00[0x28];
    Link24f9e0* points;

    float Function24f9e0();
};
