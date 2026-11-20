// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterDisplacementNormals: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b290 BSImagespaceShaderWaterDisplacementNormals::Unk_0D
// Adapted bodies: none
// g_waterDisplacementNormalsBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterDisplacementNormals.h"

extern const char g_waterDisplacementNormalsBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterDisplacementNormals::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterDisplacementNormalsBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
