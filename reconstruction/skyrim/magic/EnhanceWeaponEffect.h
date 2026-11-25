// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Code origin: Written for this reconstruction from the listing: a const getter returning a global float.
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EnhanceWeaponEffect.cpp:67 (EnhanceWeaponEffect::Start)
// EnhanceWeaponEffect, Start: GUESS(low)
// Function64d400, memberA8: GUESS(low); getter and dword at the offset the listing reads
#pragma once
#include <cstdint>
// ActiveEffect, Dispel, ValueModifierEffect, Start, SetWeaponEnchantment: GUESS(low)
class ActiveEffect { public: void Dispel(bool); };
class ValueModifierEffect : public ActiveEffect { public: void Start(); };
class EnhanceWeaponEffect : public ValueModifierEffect { public: bool SetWeaponEnchantment(); void Start(); std::uint32_t Function64d400() const; float Function64d3f0() const; private: std::uint8_t padding[0xA8]; std::uint32_t memberA8; };
