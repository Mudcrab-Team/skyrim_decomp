// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSShaderAccumulator: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1521360: GUESS(low); provisional member name
// 0x1521360 BSShaderAccumulator::Function1521360
// CI hash: 0x1521360 ?Function1521360@BSShaderAccumulator@@QEAAXHI@Z
#include "BSShaderAccumulator_1521360.h"

// Guess: Update an existing material or bind its fallback shader state.
void BSShaderAccumulator::Function1521360(int slot, unsigned value)
{
    auto* material = table->materials[slot];
    if (material) {
        if ((material->flags & 1u) > 0u) { material->Apply(value); }
        else { Bind(1, 0x5c006074, value, slot); }
    }
}
