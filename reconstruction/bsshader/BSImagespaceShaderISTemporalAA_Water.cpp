// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISTemporalAA_Water: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150ac60 BSImagespaceShaderISTemporalAA_Water::Unk_0D
// Adapted bodies: none
// g_isTemporalAA_WaterBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISTemporalAA_Water.h"

extern const char g_isTemporalAA_WaterBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISTemporalAA_Water::Unk_0D(const void** bindings)
{
    bindings[0] = g_isTemporalAA_WaterBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
