// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSLightingShader: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function154acd0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// TechniqueFlags, TechniqueClass: GUESS(low); technique metadata helpers
extern "C" unsigned TechniqueFlags(unsigned);
extern "C" unsigned TechniqueClass(unsigned);

class BSLightingShader
{
public:
    void Apply(unsigned);

    void Function154acd0(unsigned technique);
};
