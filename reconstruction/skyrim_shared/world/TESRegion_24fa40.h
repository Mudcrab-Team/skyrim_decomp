// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESRegion: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function24fa40: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Point24fa40, Link24fa40, regionBound24fa40: GUESS(low) STANDIN; region boundary points
struct Point24fa40 { float Get(); };
struct Link24fa40 { Point24fa40* point; Link24fa40* next; };
extern float regionBound24fa40;

class TESRegion
{
public:
    std::uint8_t unknown00[0x28];
    Link24fa40* points;

    float Function24fa40();
};
