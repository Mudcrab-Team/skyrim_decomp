// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderLensFlareVisibility: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x1530870 BSImagespaceShaderLensFlareVisibility::Unk_0D
// Adapted bodies: none
// g_lensFlareVisibilityBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderLensFlareVisibility.h"

extern const char g_lensFlareVisibilityBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderLensFlareVisibility::Unk_0D(const void** bindings)
{
    bindings[0] = g_lensFlareVisibilityBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
