// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original; reconstructed from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// BSImagespaceShaderISLightingCompositeMenu, BSImagespaceShaderISLightingCompositeMenu::Unk_0D: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Unk0DInfo
{
    void* volatile f00;
    void* volatile f08;
    void* volatile f10;
    void* volatile f18;
    void* volatile f20;
    void* volatile f28;
};
static_assert(sizeof(Unk0DInfo) == 0x30, "Unk0DInfo size");

class BSImagespaceShaderISLightingCompositeMenu
{
public:
    Unk0DInfo* Unk_0D(Unk0DInfo* a_out);
};
