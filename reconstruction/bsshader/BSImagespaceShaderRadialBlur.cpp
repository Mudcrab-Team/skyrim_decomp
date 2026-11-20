// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderRadialBlur: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b010 BSImagespaceShaderRadialBlur::Unk_0D
// Adapted bodies: none
// g_radialBlurBinding, g_radialBlurBinding2: GUESS(low)
#include "BSImagespaceShaderRadialBlur.h"

extern const char g_radialBlurBinding[];
extern const char g_radialBlurBinding2[];

const void** BSImagespaceShaderRadialBlur::Unk_0D(const void** bindings)
{
    bindings[0] = g_radialBlurBinding;
    bindings[1] = g_radialBlurBinding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
