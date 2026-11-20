// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Movement/MovementHandlerAgentPlayerControls.cpp:129
// MovementHandlerAgentPlayerControls, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7a3f10 MovementHandlerAgentPlayerControls::QClassAgentType
#include "MovementHandlerAgentPlayerControls.h"
const BSFixedString &MovementHandlerAgentPlayerControls::QClassAgentType()
{
    static BSFixedString typeString("Player Controls");
    return typeString;

}
