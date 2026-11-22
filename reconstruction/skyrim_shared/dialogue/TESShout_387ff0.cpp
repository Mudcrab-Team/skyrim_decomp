// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x387ff0 TESShout::IsSpellItem
// Adapted bodies: none
#include "TESShout_387ff0.h"

bool TESShout::IsSpellItem(SpellItem* a_spell)
{
    return variations[0].spell == a_spell || variations[1].spell == a_spell || variations[2].spell == a_spell;
}
