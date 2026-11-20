// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISSAOBlurV: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150aa30 BSImagespaceShaderISSAOBlurV::Unk_0D
// Adapted bodies: none
// g_isSAOBlurVBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISSAOBlurV.h"

extern const char g_isSAOBlurVBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISSAOBlurV::Unk_0D(const void** bindings)
{
    bindings[0] = g_isSAOBlurVBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
