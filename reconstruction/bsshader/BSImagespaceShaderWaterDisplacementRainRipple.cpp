// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterDisplacementRainRipple: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b2c0 BSImagespaceShaderWaterDisplacementRainRipple::Unk_0D
// Adapted bodies: none
// g_waterDisplacementRainRippleBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterDisplacementRainRipple.h"

extern const char g_waterDisplacementRainRippleBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterDisplacementRainRipple::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterDisplacementRainRippleBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
