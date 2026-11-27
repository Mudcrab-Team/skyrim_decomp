// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x6d66f0 Actor::CheckCast_140631CE0
// Adapted bodies: none
#include "Actor_6d66f0.h"

// Check whether any active magic caster slot can cast the given spell.
bool Actor::CheckCast_140631CE0(MagicItem* a_spell, bool a_dualCast, std::uint32_t* a_reason)
{
    bool result = false;
    bool cont   = true;
    for (std::uint32_t i = 0; i < 4 && cont; ++i) {
        if (magicCasters[i]) {
            result = magicCasters[i]->CheckCast(a_spell, a_dualCast, nullptr, a_reason, false);
        }
        cont = !result;
    }
    return result;
}
