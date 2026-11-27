// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x100f7e0 UpdateOrAssignShadowCSTexture
// CI hash: 0x100f7e0 ?UpdateOrAssignShadowCSTexture@@YAXPEAUShadowCSContext@@IH@Z
// Adapted bodies: none
#include "ShadowCSTexture.h"

// UpdateOrAssignShadowCSTexture: CRASHLOGGER_PDB(59818@2026.10.24)
void UpdateOrAssignShadowCSTexture(ShadowCSContext* a_context, std::uint32_t a_slot, std::int32_t a_index)
{
    void* texture = a_context->bindings[a_index].texture;
    if (g_shadowCSState.textures[a_slot] != texture) {
        g_shadowCSState.textures[a_slot] = texture;
        g_shadowCSState.textureDirty |= 1u << a_slot;
        if (g_shadowCSState.modes[a_slot] != 0) {
            g_shadowCSState.modes[a_slot] = 0;
            g_shadowCSState.modeDirty |= 1u << a_slot;
        }
    }
}
