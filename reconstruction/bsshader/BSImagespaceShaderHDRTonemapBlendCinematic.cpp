// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderHDRTonemapBlendCinematic: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a400 BSImagespaceShaderHDRTonemapBlendCinematic::Unk_0D
// Adapted bodies: none
// g_hDRDownSample4Binding2, g_hDRTonemapBlendCinematicBinding: GUESS(low)
#include "BSImagespaceShaderHDRTonemapBlendCinematic.h"

extern const char g_hDRDownSample4Binding2[];
extern const char g_hDRTonemapBlendCinematicBinding[];

const void** BSImagespaceShaderHDRTonemapBlendCinematic::Unk_0D(const void** bindings)
{
    bindings[0] = g_hDRTonemapBlendCinematicBinding;
    bindings[1] = g_hDRDownSample4Binding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
