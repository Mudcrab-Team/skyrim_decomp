// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderISDownsampleIgnoreBrightestCS: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a760 BSImagespaceShaderISDownsampleIgnoreBrightestCS::Unk_0D
// Adapted bodies: none
// g_iSDownsampleIgnoreBrightestCSBinding, g_iSDownsampleIgnoreBrightestCSBinding2: GUESS(low)
#include "BSImagespaceShaderISDownsampleIgnoreBrightestCS.h"

extern const char g_iSDownsampleIgnoreBrightestCSBinding[];
extern const char g_iSDownsampleIgnoreBrightestCSBinding2[];

const void** BSImagespaceShaderISDownsampleIgnoreBrightestCS::Unk_0D(const void** bindings)
{
    bindings[0] = g_iSDownsampleIgnoreBrightestCSBinding;
    bindings[1] = g_iSDownsampleIgnoreBrightestCSBinding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
