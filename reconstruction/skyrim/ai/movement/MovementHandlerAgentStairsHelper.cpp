// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing; the setter and clearer are plain member stores.
// 0x7a6750 MovementHandlerAgentStairsHelper::Function7a6750
// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentStairsHelper.cpp:23
// MovementHandlerAgentStairsHelper, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7a6680 MovementHandlerAgentStairsHelper::QClassAgentType
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "MovementHandlerAgentStairsHelper.h"

void MovementHandlerAgentStairsHelper::Function7a6750()
{
    _field28 = nullptr;
}

const BSFixedString &MovementHandlerAgentStairsHelper::QClassAgentType()
{
    static BSFixedString typeString("Stairs Helper");
    return typeString;

}
