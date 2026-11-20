// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderDistantBlur: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a0e0 BSImagespaceShaderDistantBlur::Unk_0D
// Adapted bodies: none
// g_distantBlurBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderDistantBlur.h"

extern const char g_distantBlurBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderDistantBlur::Unk_0D(const void** bindings)
{
    bindings[0] = g_distantBlurBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
