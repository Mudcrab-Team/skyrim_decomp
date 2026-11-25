// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSShaderAccumulator: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1520900: GUESS(low); provisional member name
// 0x1520900 BSShaderAccumulator::Function1520900
// CI hash: 0x1520900 ?Function1520900@BSShaderAccumulator@@QEAAXI@Z
#include "BSShaderAccumulator_1520900.h"

// Guess: Update material slot fourteen when accumulator state exists.
void BSShaderAccumulator::Function1520900(unsigned value)
{
    if (state) {
        auto* material = table->materials[14];
        if (material) {
            if ((material->flags & 1u) > 0u) { material->Apply(value); }
            else { Bind(1, 0x5c006074, value, 14); }
        }
    }
}
