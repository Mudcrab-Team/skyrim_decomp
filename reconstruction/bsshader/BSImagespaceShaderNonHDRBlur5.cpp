// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderNonHDRBlur5: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150af80 BSImagespaceShaderNonHDRBlur5::Unk_0D
// Adapted bodies: none
// g_nonHDRBlur11Binding, g_nonHDRBlur5Binding2: GUESS(low)
#include "BSImagespaceShaderNonHDRBlur5.h"

extern const char g_nonHDRBlur11Binding[];
extern const char g_nonHDRBlur5Binding2[];

const void** BSImagespaceShaderNonHDRBlur5::Unk_0D(const void** bindings)
{
    bindings[0] = g_nonHDRBlur11Binding;
    bindings[1] = g_nonHDRBlur5Binding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
