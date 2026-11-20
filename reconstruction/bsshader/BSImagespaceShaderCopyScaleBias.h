// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderCopyScaleBias: EXE_RTTI
// Unk_0D, Unk_0A: GUESS(low)
// ScaleBiasRenderContext, ScaleBiasRenderState, renderContext, state, Select: GUESS(low)
#pragma once

#include <cstdint>

struct ScaleBiasRenderState
{
    void Select(std::uint32_t mode);
};

struct ScaleBiasRenderContext
{
    std::uint8_t padding00[8];
    ScaleBiasRenderState* state;
};

class BSImagespaceShaderCopyScaleBias
{
public:
    const void** Unk_0D(const void** bindings);
    void Unk_0A();

private:
    std::uint8_t padding00[0xD8];
    ScaleBiasRenderContext* renderContext;
};
