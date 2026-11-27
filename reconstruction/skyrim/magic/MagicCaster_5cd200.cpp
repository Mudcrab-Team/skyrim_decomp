// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5cd200 MagicCaster::SetCurrentSpell
// Adapted bodies: MagicCaster::SetCurrentSpell, from the anonymous permitted sibling game code, rewritten
// Sibling source: fo4-private@1b765c70 src/Game/Magic/MagicCaster.cpp:33
#include "MagicCaster_5cd200.h"

// Selecting a spell arms the charge timer; clearing it resets the timing state and cost.
void MagicCaster::SetCurrentSpell(MagicItem* a_spell)
{
    currentSpell = a_spell;
    if (a_spell) {
        SetCastingTimerForCharge();
    } else {
        nextTargetUpdate = 0.0f;
        castingTimer = 0.0f;
        currentSpellCost = 1.0f;
    }
    state = 0;
    SetCurrentSpellImpl(a_spell);
}
