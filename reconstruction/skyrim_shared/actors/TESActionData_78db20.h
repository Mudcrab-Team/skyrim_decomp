// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESActionData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetSourceActorState, Process: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR, Actor, ActorState: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// source: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// actorState: GUESS(low)
#pragma once

#include <cstdint>

class TESObjectREFR
{
public:
    std::uint8_t padding00[0x1A];
    std::uint8_t formType;
};
class ActorState {};
class Actor : public TESObjectREFR
{
public:
    std::uint8_t padding1B[0xC0 - 0x1B];
    ActorState actorState;
};

class TESActionData
{
public:
    ActorState* GetSourceActorState() const;
    void Process();

private:
    std::uint8_t padding00[8];
    TESObjectREFR* source;
};
