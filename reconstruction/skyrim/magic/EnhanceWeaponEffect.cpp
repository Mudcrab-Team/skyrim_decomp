// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EnhanceWeaponEffect.cpp:67 (EnhanceWeaponEffect::Start)
// EnhanceWeaponEffect, Start: GUESS(low)
// 0x64d0b0 EnhanceWeaponEffect::Start
// Code origin: original from the listing and community declarations, except EnhanceWeaponEffect::Start, adapted from the sibling named above; Function64d3f0: written from the listing; Start adapted from the sibling named above
// 0x64d400 EnhanceWeaponEffect::Function64d400
// SPDX-License-Identifier: CC0-1.0
// 0x64d3f0 EnhanceWeaponEffect::Function64d3f0
// Adapted bodies: EnhanceWeaponEffect::Start from fo4-private@1b765c70 src/Game/Magic/EnhanceWeaponEffect.cpp (author-permission)
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "EnhanceWeaponEffect.h"

extern float g_enhanceWeaponValue; // guess(low)

void EnhanceWeaponEffect::Start() { if (!SetWeaponEnchantment()) Dispel(true); else ValueModifierEffect::Start(); }

std::uint32_t EnhanceWeaponEffect::Function64d400() const
{
    return memberA8;
}

float EnhanceWeaponEffect::Function64d3f0() const
{
    return g_enhanceWeaponValue;
}
