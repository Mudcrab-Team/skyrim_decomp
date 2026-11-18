// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/EnhanceWeaponEffect.cpp:67 (EnhanceWeaponEffect::Start)
// EnhanceWeaponEffect, Start: GUESS(low)
// 0x64d0b0 EnhanceWeaponEffect::Start
#include "EnhanceWeaponEffect.h"
void EnhanceWeaponEffect::Start() { if (!SetWeaponEnchantment()) Dispel(true); else ValueModifierEffect::Start(); }
