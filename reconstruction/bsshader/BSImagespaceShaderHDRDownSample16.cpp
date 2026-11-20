// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderHDRDownSample16: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a1f0 BSImagespaceShaderHDRDownSample16::Unk_0D
// Adapted bodies: none
// g_hDRDownSample16Binding, g_hDRDownSample16Binding2: GUESS(low)
#include "BSImagespaceShaderHDRDownSample16.h"

extern const char g_hDRDownSample16Binding[];
extern const char g_hDRDownSample16Binding2[];

const void** BSImagespaceShaderHDRDownSample16::Unk_0D(const void** bindings)
{
    bindings[0] = g_hDRDownSample16Binding;
    bindings[1] = g_hDRDownSample16Binding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
