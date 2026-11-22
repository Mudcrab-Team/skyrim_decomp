// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: declarations from community headers; layout from the pinned image listing.
// HighActorCuller, HighActorCuller::Function73c720: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// field28, field148: GUESS(low); members read and written by the compared function.
#pragma once

#include <cstdint>
#include <cstddef>
#include "generated/crashlogger_pdb/types/MobIterOperator.h"

class Actor;

class HighActorCuller : public MobIterOperator
{
public:
    ~HighActorCuller();
    void Operate(Actor* a_actor);
    void Function73c720(void* a_arg);  // compared: 0x73c720

    std::uint8_t unknown10[0x18];  // 10
    void* field28;                 // 28
    std::uint8_t unknown30[0x118]; // 30
    void* field148;                // 148
};
static_assert(sizeof(HighActorCuller) == 0x150, "HighActorCuller size");
