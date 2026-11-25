// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESObjectLAND: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function2ac140: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-fpfast.json
#pragma once
#include <cstdint>
#include <cstddef>

// ClearWeight2ac140: GUESS(low); terrain layer update
void ClearWeight2ac140(unsigned char, unsigned short, void*);

class TESObjectLAND
{
public:
    std::uint8_t unknown00[0x40];
    void* data;
    float ReadWeight(unsigned char, unsigned short);
    void Refresh();

    bool Function2ac140(unsigned char quadrant, float threshold);
};
