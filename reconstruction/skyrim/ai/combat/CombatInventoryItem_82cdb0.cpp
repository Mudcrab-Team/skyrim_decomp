// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x82cdb0 CombatInventoryItem::Function82cdb0
// Adapted bodies: none
#include "CombatInventoryItem_82cdb0.h"

bool CombatInventoryItem::Function82cdb0(TESForm* a_form)
{
    if (a_form && a_form->unk1A == 0x2E && a_form->IsTemporaryFormID()) {
        if (!gBGSSaveLoadGame || !TestBit(gBGSSaveLoadGame->unk340, 1)) {
            return true;
        }
    }
    return false;
}
