// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderISDisplayDepth: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a680 BSImagespaceShaderISDisplayDepth::Unk_0D
// Adapted bodies: none
// g_iSDisplayDepthBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISDisplayDepth.h"

extern const char g_iSDisplayDepthBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISDisplayDepth::Unk_0D(const void** bindings)
{
    bindings[0] = g_iSDisplayDepthBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
