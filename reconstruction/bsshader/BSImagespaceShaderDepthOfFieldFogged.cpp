// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderDepthOfFieldFogged: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a070 BSImagespaceShaderDepthOfFieldFogged::Unk_0D
// Adapted bodies: none
// g_depthOfFieldFoggedBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderDepthOfFieldFogged.h"

extern const char g_depthOfFieldFoggedBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderDepthOfFieldFogged::Unk_0D(const void** bindings)
{
    bindings[0] = g_depthOfFieldFoggedBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
