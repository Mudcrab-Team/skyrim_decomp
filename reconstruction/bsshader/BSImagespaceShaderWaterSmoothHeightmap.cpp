// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterSmoothHeightmap: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b3b0 BSImagespaceShaderWaterSmoothHeightmap::Unk_0D
// Adapted bodies: none
// g_waterSmoothHeightmapBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterSmoothHeightmap.h"

extern const char g_waterSmoothHeightmapBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterSmoothHeightmap::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterSmoothHeightmapBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
