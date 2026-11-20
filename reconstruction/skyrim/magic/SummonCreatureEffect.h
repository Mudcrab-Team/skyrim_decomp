// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// SummonCreatureEffect, HandleEvent, DoSummon, FixedString, data, placeActorTag: GUESS(low)
#pragma once
struct FixedString { const char* data; };
extern FixedString placeActorTag;
class SummonCreatureEffect { public: void HandleEvent(const FixedString&); void DoSummon(); };
