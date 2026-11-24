// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: Written for this reconstruction from the listing: a derived destructor that stores its vtable and tail-calls the base destructor.
// 0x7ab9a0 MovementTweenerAgentNodeFollower::Function7ab9a0
// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementTweenerAgentNodeFollower.cpp:64
// MovementTweenerAgentNodeFollower, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7ab640 MovementTweenerAgentNodeFollower::QClassAgentType
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "MovementTweenerAgentNodeFollower.h"
const BSFixedString &MovementTweenerAgentNodeFollower::QClassAgentType()
{
    static BSFixedString typeString("Node Follower");
    return typeString;
}

void MovementTweenerAgentNodeFollower::Function7ab9a0()
{
    this->MovementTweenerAgentNodeFollower::~MovementTweenerAgentNodeFollower();
}
