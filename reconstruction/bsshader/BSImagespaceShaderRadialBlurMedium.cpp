// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderRadialBlurMedium: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b070 BSImagespaceShaderRadialBlurMedium::Unk_0D
// Adapted bodies: none
// g_radialBlurBinding, g_radialBlurMediumBinding2: GUESS(low)
#include "BSImagespaceShaderRadialBlurMedium.h"

extern const char g_radialBlurBinding[];
extern const char g_radialBlurMediumBinding2[];

const void** BSImagespaceShaderRadialBlurMedium::Unk_0D(const void** bindings)
{
    bindings[0] = g_radialBlurBinding;
    bindings[1] = g_radialBlurMediumBinding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
