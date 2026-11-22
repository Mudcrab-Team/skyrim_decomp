// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorState, ActorState::actorState1, ActorState::actorState2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorState2::talkingToPlayer, ActorState2::forceRun, ActorState2::forceSneak, ActorState2::headTracking, ActorState2::reanimating, ActorState2::wantBlocking, ActorState2::flightBlocked, ActorState2::allowFlying, ActorState2::staggered: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorState2::weaponState, ActorState2::recoil, ActorState2::unk14: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; weaponState is a plain 3-bit field here, unk14 is split into its first bit and the rest
// ActorState::ctor: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorState::~ActorState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the base class IMovementState is folded into the vtable pointer
#pragma once

#include <cstdint>

class ActorState
{
public:
    struct ActorState2
    {
        std::uint32_t talkingToPlayer : 1;
        std::uint32_t forceRun : 1;
        std::uint32_t forceSneak : 1;
        std::uint32_t headTracking : 1;
        std::uint32_t reanimating : 1;
        std::uint32_t weaponState : 3;
        std::uint32_t wantBlocking : 1;
        std::uint32_t flightBlocked : 1;
        std::uint32_t recoil : 2;
        std::uint32_t allowFlying : 1;
        std::uint32_t staggered : 1;
        std::uint32_t unk14 : 1;
        std::uint32_t unk15 : 17;
    };

    ActorState();
    virtual ~ActorState();

    std::uint32_t actorState1;
    ActorState2 actorState2;
};
