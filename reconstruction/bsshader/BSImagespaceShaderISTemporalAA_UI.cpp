// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISTemporalAA_UI: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150ac30 BSImagespaceShaderISTemporalAA_UI::Unk_0D
// Adapted bodies: none
// g_isTemporalAA_UIBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISTemporalAA_UI.h"

extern const char g_isTemporalAA_UIBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISTemporalAA_UI::Unk_0D(const void** bindings)
{
    bindings[0] = g_isTemporalAA_UIBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
