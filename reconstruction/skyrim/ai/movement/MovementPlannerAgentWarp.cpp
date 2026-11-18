// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementPlannerAgentWarp.cpp:67
// MovementPlannerAgentWarp, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7a9340 MovementPlannerAgentWarp::QClassAgentType
#include "MovementPlannerAgentWarp.h"
const BSFixedString &MovementPlannerAgentWarp::QClassAgentType()
{
    static BSFixedString typeString("FailSafe Warp");
    return typeString;

}
