// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/GameMovementAgentSaveLoadCompatibility.cpp:59
// MovementPlannerAgentHorseControlsLoadScrapper, QClassAgentType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x7a7fa0 MovementPlannerAgentHorseControlsLoadScrapper::QClassAgentType
#include "MovementPlannerAgentHorseControlsLoadScrapper.h"
const BSFixedString &MovementPlannerAgentHorseControlsLoadScrapper::QClassAgentType()
{
    static BSFixedString typeString("Planner Horse Controls");
    return typeString;

}
