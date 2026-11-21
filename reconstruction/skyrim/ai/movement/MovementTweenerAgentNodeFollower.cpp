// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// TweenerBaseStandIn: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementTweenerAgentNodeFollower.cpp:64
// MovementTweenerAgentNodeFollower, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7ab640 MovementTweenerAgentNodeFollower::QClassAgentType
// Code origin: original; the pinned listing, target RTTI contract and stand-ins only
// SPDX-License-Identifier: CC0-1.0
// 0x7ab9a0 MovementTweenerAgentNodeFollower::dtor
// Adapted bodies: QClassAgentType follows fo4-private@1b765c70 src/Game/AI/Movement/MovementTweenerAgentNodeFollower.cpp:64 (author permission).
#include "MovementTweenerAgentNodeFollower.h"
const BSFixedString &MovementTweenerAgentNodeFollower::QClassAgentType()
{
    static BSFixedString typeString("Node Follower");
    return typeString;

}
MovementTweenerAgentNodeFollower::~MovementTweenerAgentNodeFollower() {}
