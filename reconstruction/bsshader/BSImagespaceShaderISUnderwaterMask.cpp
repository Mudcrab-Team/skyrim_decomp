// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISUnderwaterMask: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150ac90 BSImagespaceShaderISUnderwaterMask::Unk_0D
// Adapted bodies: none
// g_isUnderwaterMaskBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISUnderwaterMask.h"

extern const char g_isUnderwaterMaskBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISUnderwaterMask::Unk_0D(const void** bindings)
{
    bindings[0] = g_isUnderwaterMaskBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
