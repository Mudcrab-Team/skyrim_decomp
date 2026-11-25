// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSParticleShaderProperty: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function15336e0: GUESS(low); provisional member name
// 0x15336e0 BSParticleShaderProperty::Function15336e0
// CI hash: 0x15336e0 ?Function15336e0@BSParticleShaderProperty@@QEAAIXZ
#include "BSParticleShaderProperty_15336e0.h"

// Guess: Sum the geometry element counts.
unsigned BSParticleShaderProperty::Function15336e0()
{
    unsigned total = 0;
    for (unsigned i = 0; i < count; ++i) { total += geometries[i]->count; }
    return total;
}
