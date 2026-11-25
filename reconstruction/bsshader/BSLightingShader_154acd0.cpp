// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSLightingShader: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function154acd0: GUESS(low); provisional member name
// 0x154acd0 BSLightingShader::Function154acd0
// CI hash: 0x154acd0 ?Function154acd0@BSLightingShader@@QEAAXI@Z
#include "BSLightingShader_154acd0.h"

// Guess: Apply techniques outside the two excluded categories.
void BSLightingShader::Function154acd0(unsigned technique)
{
    unsigned kind = TechniqueClass(TechniqueFlags(technique));
    if (((kind - 1) & ~0x400u) != 0) { Apply(kind); }
}
