// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderWaterFlow: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b350 BSImagespaceShaderWaterFlow::Unk_0D
// Adapted bodies: none
// g_waterFlowBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderWaterFlow.h"

extern const char g_waterFlowBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderWaterFlow::Unk_0D(const void** bindings)
{
    bindings[0] = g_waterFlowBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
