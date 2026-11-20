// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderCopyDynamicFetchDisabled: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a000 BSImagespaceShaderCopyDynamicFetchDisabled::Unk_0D
// Adapted bodies: none
// g_copyDynamicFetchDisabledBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderCopyDynamicFetchDisabled.h"

extern const char g_copyDynamicFetchDisabledBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderCopyDynamicFetchDisabled::Unk_0D(const void** bindings)
{
    bindings[0] = g_copyDynamicFetchDisabledBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
