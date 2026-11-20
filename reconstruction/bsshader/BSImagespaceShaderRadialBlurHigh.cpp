// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderRadialBlurHigh: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b040 BSImagespaceShaderRadialBlurHigh::Unk_0D
// Adapted bodies: none
// g_radialBlurBinding, g_radialBlurHighBinding2: GUESS(low)
#include "BSImagespaceShaderRadialBlurHigh.h"

extern const char g_radialBlurBinding[];
extern const char g_radialBlurHighBinding2[];

const void** BSImagespaceShaderRadialBlurHigh::Unk_0D(const void** bindings)
{
    bindings[0] = g_radialBlurBinding;
    bindings[1] = g_radialBlurHighBinding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
