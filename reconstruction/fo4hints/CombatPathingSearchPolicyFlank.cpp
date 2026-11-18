// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorFlankingMovement.cpp:354
// CombatPathingSearchPolicyFlank, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x89d9c0 CombatPathingSearchPolicyFlank::GetClassType
#include "CombatPathingSearchPolicyFlank.h"
unsigned int CombatPathingSearchPolicyFlank::GetClassType()
{
    static unsigned int uiclassType = [] {
        unsigned int aiCRC = 0;
        BSCRC32::GenerateCRC(aiCRC, "CombatPathingSearchPolicyFlank", 0);
        return aiCRC;
    }();
    return uiclassType;

}
