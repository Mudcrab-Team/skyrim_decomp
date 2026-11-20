// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderNoiseNormalmap: EXE_RTTI
// Unk_0D, Unk_0B, Unk_0A: GUESS(low)
// 0x150ae60 BSImagespaceShaderNoiseNormalmap::Unk_0D
// 0x150b4d0 BSImagespaceShaderNoiseNormalmap::Unk_0B
// 0x150b570 BSImagespaceShaderNoiseNormalmap::Unk_0A
// Adapted bodies: none
// g_noiseNormalmapBinding, g_imageSpaceRenderMode, g_imageSpaceDirtyState: GUESS(low)
// kEmptyString: OBSERVED
#include "BSImagespaceShaderNoiseNormalmap.h"

#include <cstdint>

extern const char g_noiseNormalmapBinding[];
extern const char kEmptyString[];
extern std::uint32_t g_imageSpaceRenderMode;
extern std::uint32_t g_imageSpaceDirtyState;

const void** BSImagespaceShaderNoiseNormalmap::Unk_0D(const void** bindings)
{
    bindings[0] = g_noiseNormalmapBinding;
    bindings[1] = kEmptyString;
    bindings[2] = nullptr;
    bindings[3] = nullptr;
    return bindings;
}

void BSImagespaceShaderNoiseNormalmap::Unk_0B()
{
    if (g_imageSpaceRenderMode != 1) {
        g_imageSpaceDirtyState |= 0x80;
        g_imageSpaceRenderMode = 1;
    }
}

void BSImagespaceShaderNoiseNormalmap::Unk_0A()
{
    if (g_imageSpaceRenderMode != 2) {
        g_imageSpaceDirtyState |= 0x80;
        g_imageSpaceRenderMode = 2;
    }
}
