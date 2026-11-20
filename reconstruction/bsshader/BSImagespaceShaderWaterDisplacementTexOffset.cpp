// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterDisplacementTexOffset: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b2f0 BSImagespaceShaderWaterDisplacementTexOffset::Unk_0D
// Adapted bodies: none
// g_waterDisplacementTexOffsetBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterDisplacementTexOffset.h"

extern const char g_waterDisplacementTexOffsetBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterDisplacementTexOffset::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterDisplacementTexOffsetBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
