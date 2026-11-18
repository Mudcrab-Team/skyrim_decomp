// Code origin: body written by the contributor from the compared function's behaviour; names and
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0x53a270 BGSStoryTeller::ProcessEvent
#include "BGSStoryTeller.h"

BSEventNotifyControl BGSStoryTeller::ProcessEvent(const TESQuestStageItemDoneEvent* a_event, BSTEventSource<TESQuestStageItemDoneEvent>* a_eventSource)
{
    QuestStageItemDone(a_event->formID, a_event->stage, a_event->flag);
    return BSEventNotifyControl::kContinue;
}
