// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterBlendHeightmaps: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b230 BSImagespaceShaderWaterBlendHeightmaps::Unk_0D
// Adapted bodies: none
// g_waterBlendHeightmapsBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterBlendHeightmaps.h"

extern const char g_waterBlendHeightmapsBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterBlendHeightmaps::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterBlendHeightmapsBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
