// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiCapsuleBV: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionf39b40: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-fpfast.json
#pragma once
#include <cstdint>
#include <cstddef>

// Vecf39b40: GUESS(low) STANDIN; three-component vector
struct Vecf39b40 { float x; float y; float z; Vecf39b40& operator=(const Vecf39b40& a) { x=a.x; y=a.y; z=a.z; return *this; } void Scale(float v) { x*=v; y*=v; z*=v; } void Add(const Vecf39b40& a) { x+=a.x; y+=a.y; z+=a.z; } };

class NiCapsuleBV
{
public:
    std::uint64_t unknown00;
    Vecf39b40 center;
    Vecf39b40 direction;
    float radiusStart;
    Vecf39b40 start;
    Vecf39b40 extent;
    float radiusEnd;

    void Functionf39b40();
};
