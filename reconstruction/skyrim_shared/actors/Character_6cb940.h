// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); placeholder class, a view of the actor-state word only
// Character::IsInAttackState: GUESS(low)
// ActorState1, actorState1, meleeAttackState, ATTACK_STATE_ENUM, kNone, kDraw, kSwing, kHit, kNextAttack, kFollowThrough, kBash, kBowDraw, kBowAttached, kBowDrawn, kBowReleasing, kBowReleased, kBowNextAttack, kBowFollowThrough, kFire, GetAttackState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's ActorState base sits 8 bytes later in this build, modelled as a member word
// ActorState1::bits00: GUESS(low); the bit-fields below meleeAttackState, unnamed here
#pragma once

#include <cstdint>
#include <cstddef>

enum class ATTACK_STATE_ENUM : std::uint32_t
{
    kNone = 0,
    kDraw = 1,
    kSwing = 2,
    kHit = 3,
    kNextAttack = 4,
    kFollowThrough = 5,
    kBash = 6,
    kBowDraw = 8,
    kBowAttached = 9,
    kBowDrawn = 10,
    kBowReleasing = 11,
    kBowReleased = 12,
    kBowNextAttack = 13,
    kBowFollowThrough = 14,
    kFire = 15
};

struct ActorState1
{
    std::uint32_t     bits00 : 28;           // 0:00
    ATTACK_STATE_ENUM meleeAttackState : 4;  // 0:28
};

class Character
{
public:
    ATTACK_STATE_ENUM GetAttackState() const { return actorState1.meleeAttackState; }

    bool IsInAttackState() const;  // compared: 0x6cb940
    std::uint8_t pad00[0xC8];
    ActorState1  actorState1;  // C8
};
