// CI hash: 0x4432f0 ?Function4432f0@ActorValueList@@SAPEAUActorValueEntryView@@H@Z
// Source exposure: mixed (pinned-image observations and community layout declarations).
// Code origin: original bounds-checked table accessors.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueList, ActorValueList::actorValues: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValueEntryView, ActorValueEntryView::value, ActorValueEntryView::unknown00, ActorValueList::unknown00, gActorValues: GUESS(low)
// ActorValueList::Function4432f0, ActorValueList::Function4430e0: GUESS(low)
// 0x4432f0 ActorValueList::Function4432f0
#include "ActorValueList_4432f0.h"

// Read the indexed actor-value record after checking its range.
ActorValueEntryView* ActorValueList::Function4432f0(std::int32_t index)
{
    return static_cast<std::uint32_t>(index) <= 163 ? GetSingleton()->actorValues[index] : nullptr;
}
