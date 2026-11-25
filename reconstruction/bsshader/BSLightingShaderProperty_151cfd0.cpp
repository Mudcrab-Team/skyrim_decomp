// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSLightingShaderProperty: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function151cfd0: GUESS(low); provisional member name
// 0x151cfd0 BSLightingShaderProperty::Function151cfd0
// CI hash: 0x151cfd0 ?Function151cfd0@BSLightingShaderProperty@@QEAAXI@Z
#include "BSLightingShaderProperty_151cfd0.h"

// Guess: Apply both shader variants and repeat without the optional flag.
void BSLightingShaderProperty::Function151cfd0(unsigned flags)
{
    Apply(flags);
    Apply(flags | 0x6000);
    if (flags & 0x200) {
        flags &= ~0x200u;
        Apply(flags);
        Apply(flags | 0x6000);
    }
}
