// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISPerlinNoise2DCS: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a990 BSImagespaceShaderISPerlinNoise2DCS::Unk_0D
// Adapted bodies: none
// g_isPerlinNoise2DCSBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISPerlinNoise2DCS.h"

extern const char g_isPerlinNoise2DCSBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISPerlinNoise2DCS::Unk_0D(const void** bindings)
{
    bindings[0] = g_isPerlinNoise2DCSBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
