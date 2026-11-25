// Source exposure: mixed
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetMoveModeForMaxSpeed: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/ActorState.cpp:13
// Body adapted from the sibling's movement-mode selection.
// 0x6e1410 ActorState::GetMoveModeForMaxSpeed
#include "ActorState_6e1410.h"

std::uint16_t ActorState::GetMoveModeForMaxSpeed(std::uint8_t speed)
{
    std::uint16_t mode = 0xF3F;
    mode &= actorState1;
    std::uint16_t speedMode;
    switch (speed) {
    case 1: speedMode = 0x1000; break;
    case 2: speedMode = 0x80; break;
    case 3: speedMode = 0x2000; break;
    default: speedMode = 0x40; break;
    }
    return speedMode | mode;
}
