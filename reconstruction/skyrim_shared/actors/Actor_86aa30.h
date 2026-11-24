// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a view of the actor-state word at 0xcc only
// Actor::Function86aa30: GUESS(low); placeholder name kept, true when the actor is staggered or its recoil state is 2
// ActorState2 ActorState2::recoil ActorState2::staggered: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); bits 10-11 and 13 of the word at 0xcc
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

#include <cstdint>
#include <cstddef>

struct ActorState2
{
    std::uint32_t talkingToPlayer: 1;
    std::uint32_t forceRun: 1;
    std::uint32_t forceSneak: 1;
    std::uint32_t headTracking: 1;
    std::uint32_t reanimating: 1;
    std::uint32_t weaponState: 3;
    std::uint32_t wantBlocking: 1;
    std::uint32_t flightBlocked: 1;
    std::uint32_t recoil: 2;
    std::uint32_t allowFlying: 1;
    std::uint32_t staggered: 1;
    std::uint32_t unk14: 18;
};
static_assert(sizeof(ActorState2) == 0x4, "ActorState2 size");

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Actor
{
public:
    bool Function86aa30();  // compared: 0x86aa30

    std::uint8_t pad00[0xcc];
    ActorState2 actorState2;  // 0xcc
};
static_assert(offsetof(Actor, actorState2) == 0xcc, "actorState2");
