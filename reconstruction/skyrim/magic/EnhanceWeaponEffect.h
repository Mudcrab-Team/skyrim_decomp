// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EnhanceWeaponEffect.cpp:67 (EnhanceWeaponEffect::Start)
// EnhanceWeaponEffect, Start: GUESS(low)
#pragma once
// ActiveEffect, Dispel, ValueModifierEffect, Start, SetWeaponEnchantment: GUESS(low)
class ActiveEffect { public: void Dispel(bool); };
class ValueModifierEffect : public ActiveEffect { public: void Start(); };
class EnhanceWeaponEffect : public ValueModifierEffect { public: bool SetWeaponEnchantment(); void Start(); };
