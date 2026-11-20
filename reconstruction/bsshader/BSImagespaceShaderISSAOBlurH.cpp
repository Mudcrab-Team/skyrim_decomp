// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISSAOBlurH: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a9d0 BSImagespaceShaderISSAOBlurH::Unk_0D
// Adapted bodies: none
// g_isSAOBlurHBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISSAOBlurH.h"

extern const char g_isSAOBlurHBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISSAOBlurH::Unk_0D(const void** bindings)
{
    bindings[0] = g_isSAOBlurHBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
