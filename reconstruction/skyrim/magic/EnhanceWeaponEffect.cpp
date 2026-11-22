// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x64d400 EnhanceWeaponEffect::Function64d400
// Adapted bodies: none
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EnhanceWeaponEffect.cpp:67 (EnhanceWeaponEffect::Start)
// EnhanceWeaponEffect, Start: GUESS(low)
#include "EnhanceWeaponEffect.h"
void EnhanceWeaponEffect::Start() { if (!SetWeaponEnchantment()) Dispel(true); else ValueModifierEffect::Start(); }

std::uint32_t EnhanceWeaponEffect::Function64d400() const
{
    return memberA8;
}
