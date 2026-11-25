// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorState, actorState1: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetMoveModeForMaxSpeed: SIBLING(fo4-private@1b765c70, author-permission)
// movementInterface: STANDIN GUESS(low); vptr storage only
// actorState1: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); low movement bits only
#pragma once
#include <cstddef>
#include <cstdint>

class ActorState
{
public:
    std::uint16_t GetMoveModeForMaxSpeed(std::uint8_t speed);
    void* movementInterface;
    std::uint16_t actorState1;
};
static_assert(offsetof(ActorState, actorState1) == 8, "movement-state offset");
