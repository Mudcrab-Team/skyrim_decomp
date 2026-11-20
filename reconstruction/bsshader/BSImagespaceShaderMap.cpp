// Source exposure: binary-analysis (pinned image).
// Code origin: original implementations from the pinned slot bodies.
// BSImagespaceShaderMap: EXE_RTTI
// Unk_0D, Unk_0B, Unk_0A: GUESS(low)
// 0x150ae50 BSImagespaceShaderMap::Unk_0D
// 0x150b4b0 BSImagespaceShaderMap::Unk_0B
// 0x150b550 BSImagespaceShaderMap::Unk_0A
// Adapted bodies: none
// g_imageSpaceRenderMode, g_imageSpaceDirtyState: GUESS(low)
#include "BSImagespaceShaderMap.h"

#include <cstdint>

extern std::uint32_t g_imageSpaceRenderMode;
extern std::uint32_t g_imageSpaceDirtyState;

const void** BSImagespaceShaderMap::Unk_0D(const void** bindings)
{
    bindings[0] = nullptr;
    bindings[1] = nullptr;
    return bindings;
}

void BSImagespaceShaderMap::Unk_0B()
{
    if (g_imageSpaceRenderMode != 1) {
        g_imageSpaceDirtyState |= 0x80;
        g_imageSpaceRenderMode = 1;
    }
}

void BSImagespaceShaderMap::Unk_0A()
{
    if (g_imageSpaceRenderMode != 2) {
        g_imageSpaceDirtyState |= 0x80;
        g_imageSpaceRenderMode = 2;
    }
}
