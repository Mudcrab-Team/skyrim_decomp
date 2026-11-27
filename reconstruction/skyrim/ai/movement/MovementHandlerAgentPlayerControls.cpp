// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: QClassAgentType adapted from the cited game-code body under anonymous author permission; the rest written for this reconstruction from the listing.
// Licence: fo4-private reused with author permission conditional on anonymity.
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Movement/MovementHandlerAgentPlayerControls.cpp:129
// MovementHandlerAgentPlayerControls, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7a49a0 MovementHandlerAgentPlayerControls::Function7a49a0
// 0x7a3f10 MovementHandlerAgentPlayerControls::QClassAgentType
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "MovementHandlerAgentPlayerControls.h"
const BSFixedString &MovementHandlerAgentPlayerControls::QClassAgentType()
{
    static BSFixedString typeString("Player Controls");
    return typeString;

}

void MovementHandlerAgentPlayerControls::Function7a49a0(float a_newValue)
{
    this->_unk28 = a_newValue;
}
