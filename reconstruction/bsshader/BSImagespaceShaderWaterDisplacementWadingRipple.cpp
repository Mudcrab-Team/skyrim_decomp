// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterDisplacementWadingRipple: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b320 BSImagespaceShaderWaterDisplacementWadingRipple::Unk_0D
// Adapted bodies: none
// g_waterDisplacementWadingRippleBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterDisplacementWadingRipple.h"

extern const char g_waterDisplacementWadingRippleBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterDisplacementWadingRipple::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterDisplacementWadingRippleBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
