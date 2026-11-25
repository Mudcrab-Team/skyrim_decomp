// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiParticleMeshes: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// NiParticleMeshes: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Basef15ce0: GUESS(low) STANDIN; base subobject with unobserved members
class Basef15ce0
{
public:
    Basef15ce0();
    virtual ~Basef15ce0();
    std::uint8_t unknown08[352];
};

class NiParticleMeshes : public Basef15ce0
{
public:
    unsigned unknown168;
    std::uint8_t unknown16c;

     NiParticleMeshes();
};
