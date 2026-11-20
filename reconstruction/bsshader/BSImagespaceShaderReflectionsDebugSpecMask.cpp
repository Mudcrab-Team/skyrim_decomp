// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderReflectionsDebugSpecMask: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150b1a0 BSImagespaceShaderReflectionsDebugSpecMask::Unk_0D
// Adapted bodies: none
// g_reflectionsDebugSpecMaskBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderReflectionsDebugSpecMask.h"

extern const char g_reflectionsDebugSpecMaskBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderReflectionsDebugSpecMask::Unk_0D(const void** bindings)
{
    bindings[0] = g_reflectionsDebugSpecMaskBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
