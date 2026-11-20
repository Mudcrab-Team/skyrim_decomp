// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderCopyScaleBias: EXE_RTTI
// Unk_0D, Unk_0A: GUESS(low)
// ScaleBiasRenderContext, ScaleBiasRenderState, renderContext, state, Select: GUESS(low)
// 0x150a030 BSImagespaceShaderCopyScaleBias::Unk_0D
// 0x150b530 BSImagespaceShaderCopyScaleBias::Unk_0A
// Adapted bodies: none
// g_copyScaleBiasBinding: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderCopyScaleBias.h"

extern const char g_copyScaleBiasBinding[];
extern const char kEmptyString[];

const void** BSImagespaceShaderCopyScaleBias::Unk_0D(const void** bindings)
{
    bindings[0] = g_copyScaleBiasBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}

void BSImagespaceShaderCopyScaleBias::Unk_0A()
{
    return renderContext->state->Select(3);
}
