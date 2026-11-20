// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderGreyScale: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a1c0 BSImagespaceShaderGreyScale::Unk_0D
// Adapted bodies: none
// g_greyScaleBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderGreyScale.h"

extern const char g_greyScaleBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderGreyScale::Unk_0D(const void** bindings)
{
    bindings[0] = g_greyScaleBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
