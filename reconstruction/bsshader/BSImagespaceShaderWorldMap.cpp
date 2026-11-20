// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWorldMap: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b410 BSImagespaceShaderWorldMap::Unk_0D
// Adapted bodies: none
// g_worldMapBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWorldMap.h"

extern const char g_worldMapBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWorldMap::Unk_0D(const void** bindings)
{
    bindings[0] = g_worldMapBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
