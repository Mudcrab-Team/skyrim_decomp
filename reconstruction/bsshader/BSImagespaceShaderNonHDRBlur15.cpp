// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderNonHDRBlur15: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150af20 BSImagespaceShaderNonHDRBlur15::Unk_0D
// Adapted bodies: none
// g_nonHDRBlur11Binding, g_nonHDRBlur15Binding2: GUESS(low)
#include "BSImagespaceShaderNonHDRBlur15.h"

extern const char g_nonHDRBlur11Binding[];
extern const char g_nonHDRBlur15Binding2[];

const void** BSImagespaceShaderNonHDRBlur15::Unk_0D(const void** bindings)
{
    bindings[0] = g_nonHDRBlur11Binding;
    bindings[1] = g_nonHDRBlur15Binding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
