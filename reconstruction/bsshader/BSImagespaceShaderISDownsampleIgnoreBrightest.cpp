// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderISDownsampleIgnoreBrightest: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a730 BSImagespaceShaderISDownsampleIgnoreBrightest::Unk_0D
// Adapted bodies: none
// g_iSDownsampleIgnoreBrightestBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISDownsampleIgnoreBrightest.h"

extern const char g_iSDownsampleIgnoreBrightestBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISDownsampleIgnoreBrightest::Unk_0D(const void** bindings)
{
    bindings[0] = g_iSDownsampleIgnoreBrightestBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
