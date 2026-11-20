// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderISCompositeVolumetricLighting: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a510 BSImagespaceShaderISCompositeVolumetricLighting::Unk_0D
// Adapted bodies: none
// g_iSCompositeVolumetricLightingBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISCompositeVolumetricLighting.h"

extern const char g_iSCompositeVolumetricLightingBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISCompositeVolumetricLighting::Unk_0D(const void** bindings)
{
    bindings[0] = g_iSCompositeVolumetricLightingBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
