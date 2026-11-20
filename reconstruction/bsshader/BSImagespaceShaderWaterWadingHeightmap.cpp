// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterWadingHeightmap: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b3e0 BSImagespaceShaderWaterWadingHeightmap::Unk_0D
// Adapted bodies: none
// g_waterWadingHeightmapBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterWadingHeightmap.h"

extern const char g_waterWadingHeightmapBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterWadingHeightmap::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterWadingHeightmapBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
