// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderTextureMask: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b1f0 BSImagespaceShaderTextureMask::Unk_0D
// Adapted bodies: none
// g_textureMaskBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderTextureMask.h"

extern const char g_textureMaskBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderTextureMask::Unk_0D(const void** bindings)
{
    bindings[0] = g_textureMaskBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
