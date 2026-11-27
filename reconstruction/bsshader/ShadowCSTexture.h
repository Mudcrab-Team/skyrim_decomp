// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// UpdateOrAssignShadowCSTexture: CRASHLOGGER_PDB(59818@2026.10.24)
// ShadowCSTexture, ShadowCSBinding, ShadowCSContext, ShadowCSState: GUESS(low); the unit name and shapes measured from the listing
#pragma once

class ShadowCSTexture
{
};

#include <cstdint>

struct ShadowCSBinding
{
    void* texture;
    std::uint8_t other[0x28];
};

struct ShadowCSContext
{
    std::uint8_t pad[0xA70];
    ShadowCSBinding bindings[1];
};

struct ShadowCSState
{
    std::uint8_t pad0[0xC];
    std::uint32_t textureDirty;
    std::uint32_t modeDirty;
    std::uint8_t pad1[0x22C];
    void* textures[16];
    std::uint32_t modes[16];
};

extern ShadowCSState g_shadowCSState;

void UpdateOrAssignShadowCSTexture(ShadowCSContext* a_context, std::uint32_t a_slot, std::int32_t a_index);
