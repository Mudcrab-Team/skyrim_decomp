// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterDisplacementClearSimulation: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b260 BSImagespaceShaderWaterDisplacementClearSimulation::Unk_0D
// Adapted bodies: none
// g_waterDisplacementClearSimulationBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterDisplacementClearSimulation.h"

extern const char g_waterDisplacementClearSimulationBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterDisplacementClearSimulation::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterDisplacementClearSimulationBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
