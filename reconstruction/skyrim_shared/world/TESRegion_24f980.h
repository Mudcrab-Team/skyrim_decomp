// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegion: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function24f980: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Point24f980, Link24f980, regionBound24f980: GUESS(low) STANDIN; region boundary points
struct Point24f980 { float Get(); };
struct Link24f980 { Point24f980* point; Link24f980* next; };
extern float regionBound24f980;

class TESRegion
{
public:
    std::uint8_t unknown00[0x28];
    Link24f980* points;

    float Function24f980();
};
