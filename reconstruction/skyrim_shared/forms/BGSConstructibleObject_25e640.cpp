// Source exposure: mixed (community declarations and local binary analysis).
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSConstructibleObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RemoveRequiredItem: GUESS(low); inferred full-width success result for ingredient removal
// 0x25e640 BGSConstructibleObject::RemoveRequiredItem
#include "BGSConstructibleObject_25e640.h"

unsigned int BGSConstructibleObject::RemoveRequiredItem(TESBoundObject* item, int count)
{
    unsigned handle;
    PlayerCharacter* player = PlayerCharacter::singleton;
    player->vtable->RemoveItem(player, &handle, item, count < 0 ? -count : count,
                              0, nullptr, nullptr, nullptr, nullptr);
    return 1;
}
