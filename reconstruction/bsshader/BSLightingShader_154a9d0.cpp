// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSLightingShader: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function154a9d0: GUESS(low); provisional member name
// 0x154a9d0 BSLightingShader::Function154a9d0
// CI hash: 0x154a9d0 ?Function154a9d0@BSLightingShader@@QEAAXI@Z
#include "BSLightingShader_154a9d0.h"

// Guess: Apply techniques outside the two excluded categories.
void BSLightingShader::Function154a9d0(unsigned technique)
{
    unsigned kind = TechniqueClass(TechniqueFlags(technique));
    if (((kind - 1) & ~0x400u) != 0) { Apply(kind); }
}
