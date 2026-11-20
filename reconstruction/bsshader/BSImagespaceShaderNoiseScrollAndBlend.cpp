// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderNoiseScrollAndBlend: EXE_RTTI
// Unk_0D, Unk_0B, Unk_0A: GUESS(low)
// 0x150ae90 BSImagespaceShaderNoiseScrollAndBlend::Unk_0D
// 0x150b4f0 BSImagespaceShaderNoiseScrollAndBlend::Unk_0B
// 0x150b590 BSImagespaceShaderNoiseScrollAndBlend::Unk_0A
// Adapted bodies: none
// g_noiseScrollAndBlendBinding, g_imageSpaceRenderMode, g_imageSpaceDirtyState: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderNoiseScrollAndBlend.h"

#include <cstdint>

extern const char g_noiseScrollAndBlendBinding[];
extern const char kEmptyString[];
extern std::uint32_t g_imageSpaceRenderMode;
extern std::uint32_t g_imageSpaceDirtyState;

const void** BSImagespaceShaderNoiseScrollAndBlend::Unk_0D(const void** bindings)
{
    bindings[0] = g_noiseScrollAndBlendBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}

void BSImagespaceShaderNoiseScrollAndBlend::Unk_0B()
{
    if (g_imageSpaceRenderMode != 1) {
        g_imageSpaceDirtyState |= 0x80;
        g_imageSpaceRenderMode = 1;
    }
}

void BSImagespaceShaderNoiseScrollAndBlend::Unk_0A()
{
    if (g_imageSpaceRenderMode != 2) {
        g_imageSpaceDirtyState |= 0x80;
        g_imageSpaceRenderMode = 2;
    }
}
