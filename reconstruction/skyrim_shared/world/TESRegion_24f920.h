// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegion: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function24f920: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Point24f920, Link24f920, regionBound24f920: GUESS(low) STANDIN; region boundary points
struct Point24f920 { float Get(); };
struct Link24f920 { Point24f920* point; Link24f920* next; };
extern float regionBound24f920;

class TESRegion
{
public:
    std::uint8_t unknown00[0x28];
    Link24f920* points;

    float Function24f920();
};
