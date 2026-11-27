// CI hash: 0x4430e0 ?Function4430e0@ActorValueList@@SAPEBDH@Z
// Source exposure: mixed (pinned-image observations and community layout declarations).
// Code origin: original bounds-checked table accessors.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueList, ActorValueList::actorValues: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValueEntryView, ActorValueEntryView::value, ActorValueEntryView::unknown00, ActorValueList::unknown00, gActorValues: GUESS(low)
// ActorValueList::Function4432f0, ActorValueList::Function4430e0: GUESS(low)
// 0x4430e0 ActorValueList::Function4430e0
#include "ActorValueList_4430e0.h"

// Read the indexed actor-value record after checking its range.
const char* ActorValueList::Function4430e0(std::int32_t index)
{
    if (static_cast<std::uint32_t>(index) > 163)
        return nullptr;
    ActorValueEntryView* entry = GetSingleton()->actorValues[index];
    return entry ? entry->value : nullptr;
}
