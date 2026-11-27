// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1d3690 BGSDestructibleObjectForm::sub_1401834A0
// Adapted bodies: none
#include "BGSDestructibleObjectForm_1d3690.h"

// Returns the base health actor value when a_refr is an actor, otherwise the destructible object health.
std::uint32_t BGSDestructibleObjectForm::sub_1401834A0(TESObjectREFR* a_refr) const
{
    Actor* actor = a_refr ? a_refr->AsActor() : nullptr;
    if (actor) {
        return static_cast<std::uint32_t>(actor->GetBaseActorValue(0x18));
    }
    return data->health;
}
