// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6d6780 PlayerCharacter::IsCasting
// Adapted bodies: none
#include "PlayerCharacter_6d6780.h"

// Return whether any active magic caster slot is casting the specified spell (or any spell if null).
bool PlayerCharacter::IsCasting(const MagicItem* a_spell) const
{
    std::uint8_t mask = 0;
    bool          cont = true;
    std::uint32_t i = 0;
    while (i < 4 && cont) {
        const ActorMagicCaster* caster = magicCasters[i];
        if (caster) {
            std::uint32_t source = caster->GetCastingSource();
            if (caster->currentSpell && (!a_spell || caster->currentSpell == a_spell)) {
                mask |= static_cast<std::uint8_t>(1u << source);
            }
        }
        ++i;
        cont = mask == 0;
    }
    return mask != 0;
}
