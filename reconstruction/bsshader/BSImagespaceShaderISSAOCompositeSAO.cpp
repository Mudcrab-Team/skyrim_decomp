// Source exposure: binary-analysis (pinned image).
// Code origin: original implementation from the pinned slot body.
// BSImagespaceShaderISSAOCompositeSAO: EXE_RTTI
// Unk_0D: GUESS(low)
// 0x150aaf0 BSImagespaceShaderISSAOCompositeSAO::Unk_0D
// Adapted bodies: none
// g_isSAOCompositeSAOBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderISSAOCompositeSAO.h"

extern const char g_isSAOCompositeSAOBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderISSAOCompositeSAO::Unk_0D(const void** bindings)
{
    bindings[0] = g_isSAOCompositeSAOBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}
