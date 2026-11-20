// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISMinifyContrast: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a840 BSImagespaceShaderISMinifyContrast::Unk_0D
// Adapted bodies: none
// g_isMinifyContrastBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISMinifyContrast.h"

extern const char g_isMinifyContrastBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISMinifyContrast::Unk_0D(const void** bindings)
{
    bindings[0] = g_isMinifyContrastBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
