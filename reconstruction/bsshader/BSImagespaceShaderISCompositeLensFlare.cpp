// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderISCompositeLensFlare: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150a4a0 BSImagespaceShaderISCompositeLensFlare::Unk_0D
// Adapted bodies: none
// g_iSCompositeLensFlareBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISCompositeLensFlare.h"

extern const char g_iSCompositeLensFlareBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISCompositeLensFlare::Unk_0D(const void** bindings)
{
    bindings[0] = g_iSCompositeLensFlareBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
