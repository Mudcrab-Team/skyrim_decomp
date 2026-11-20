// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISSAOBlurHCS: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150aa00 BSImagespaceShaderISSAOBlurHCS::Unk_0D
// Adapted bodies: none
// g_isSAOBlurHCSBinding, g_isSAOBlurHCSBinding2: GUESS(low)
#include "BSImagespaceShaderISSAOBlurHCS.h"

extern const char g_isSAOBlurHCSBinding[];
extern const char g_isSAOBlurHCSBinding2[];

const void** BSImagespaceShaderISSAOBlurHCS::Unk_0D(const void** bindings)
{
    bindings[0] = g_isSAOBlurHCSBinding;
    bindings[1] = g_isSAOBlurHCSBinding2;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
