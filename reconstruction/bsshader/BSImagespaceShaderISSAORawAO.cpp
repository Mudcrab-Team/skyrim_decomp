// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISSAORawAO: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150ab60 BSImagespaceShaderISSAORawAO::Unk_0D
// Adapted bodies: none
// g_isSAORawAOBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISSAORawAO.h"

extern const char g_isSAORawAOBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISSAORawAO::Unk_0D(const void** bindings)
{
    bindings[0] = g_isSAORawAOBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
