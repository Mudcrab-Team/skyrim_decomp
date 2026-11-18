// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.cpp:25
// MovementHandlerAgentSprintActionTrigger, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7a5b20 MovementHandlerAgentSprintActionTrigger::QClassAgentType
#include "MovementHandlerAgentSprintActionTrigger.h"
const BSFixedString &MovementHandlerAgentSprintActionTrigger::QClassAgentType()
{
    static BSFixedString typeString("Sprint Action Trigger");
    return typeString;

}
