// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiCamera: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioneefae0: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-fpfast.json
#pragma once
#include <cstdint>
#include <cstddef>

// Frustumeefae0: GUESS(low) STANDIN; measured camera-frustum values
struct Frustumeefae0 { float left; float right; float top; float bottom; float nearPlane; float farPlane; std::uint8_t ortho; };

class NiCamera
{
public:
    std::uint8_t unknown00[0x150];
    float left;
    float right;
    float top;
    float bottom;
    float nearPlane;
    float farPlane;
    std::uint8_t ortho;
    std::uint8_t unknown169[3];
    float minNearPlaneDist;
    float maxFarNearRatio;

    void Functioneefae0(const Frustumeefae0& frustum);
};
