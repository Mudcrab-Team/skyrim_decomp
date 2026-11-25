// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x75bf70 PlayerCharacter::ApplyPerksFromBase
// Adapted bodies: none
#include "PlayerCharacter_75bf70.h"

void PlayerCharacter::ApplyPerksFromBase()
{
    Actor::ApplyPerksFromBase();
    PerkApplier concrete(this);
    PerkEntryVisitor& applier = concrete;
    std::uint32_t count = unk4D0;
    if (count == 0) {
        return;
    }
    BGSPerkEntry** it = unk4C0;
    BGSPerkEntry** end = it + count;
    for (; it != end; ++it) {
        if (applier.Visit(*it) != 1) {
            break;
        }
    }
}
