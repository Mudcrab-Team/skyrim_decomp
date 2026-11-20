// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISSAOCompositeFog: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150aac0 BSImagespaceShaderISSAOCompositeFog::Unk_0D
// Adapted bodies: none
// g_isSAOCompositeFogBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISSAOCompositeFog.h"

extern const char g_isSAOCompositeFogBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISSAOCompositeFog::Unk_0D(const void** bindings)
{
    bindings[0] = g_isSAOCompositeFogBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
