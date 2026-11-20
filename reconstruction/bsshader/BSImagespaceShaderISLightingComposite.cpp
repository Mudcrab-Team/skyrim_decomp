// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISLightingComposite: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a7b0 BSImagespaceShaderISLightingComposite::Unk_0D
// Adapted bodies: none
// g_isLightingCompositeBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISLightingComposite.h"

extern const char g_isLightingCompositeBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISLightingComposite::Unk_0D(const void** bindings)
{
    bindings[0] = g_isLightingCompositeBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
