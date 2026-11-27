// Source exposure: mixed (pinned-image observations and community layout declarations).
// Code origin: original bounds-checked table accessors.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueList::GetSingleton: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValueList, ActorValueList::actorValues: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValueEntryView, ActorValueEntryView::value, ActorValueEntryView::unknown00, ActorValueList::unknown00, gActorValues: GUESS(low)
// ActorValueList::Function4432f0, ActorValueList::Function4430e0: GUESS(low)
#pragma once
#include <cstdint>

struct ActorValueEntryView
{
    std::uint8_t unknown00[80];
    const char* value;
};
extern "C" int __cdecl _stricmp(const char* first, const char* second);
class ActorValueList;
extern ActorValueList* gActorValues;

class ActorValueList
{
public:
    static std::uint32_t Function443320(const char* name);
    static ActorValueList* GetSingleton() { return gActorValues; }
    static ActorValueEntryView* Function4432f0(std::int32_t index);
    static const char* Function4430e0(std::int32_t index);
    std::uint64_t unknown00;
    ActorValueEntryView* actorValues[164];
};
