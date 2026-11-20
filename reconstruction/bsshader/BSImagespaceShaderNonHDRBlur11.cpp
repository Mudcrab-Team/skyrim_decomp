// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderNonHDRBlur11: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150aec0 BSImagespaceShaderNonHDRBlur11::Unk_0D
// Adapted bodies: none
// g_nonHDRBlur11Binding, g_nonHDRBlur11Binding2: GUESS(low)
#include "BSImagespaceShaderNonHDRBlur11.h"

extern const char g_nonHDRBlur11Binding[];
extern const char g_nonHDRBlur11Binding2[];

const void** BSImagespaceShaderNonHDRBlur11::Unk_0D(const void** bindings)
{
    bindings[0] = g_nonHDRBlur11Binding;
    bindings[1] = g_nonHDRBlur11Binding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
