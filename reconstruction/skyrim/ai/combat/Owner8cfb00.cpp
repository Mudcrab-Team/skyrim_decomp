// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Code origin: Stamped as a twin of matched 0x89d8a0 (skyrim/ai/combat/CombatPathingGoalPolicyFlank): source copied, names replaced by placeholders.
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorFlankingMovement.cpp:321
// 0x8cfb00 Owner8cfb00::Function8cfb00
#include "Owner8cfb00.h"

// guess: same compiled code as matched 0x89d8a0 apart from relocated fields; its role here is not established.
unsigned int Owner8cfb00::Function8cfb00()
{
    static unsigned int uiclassType = [] {
        unsigned int aiCRC = 0;
        BSCRC32::GenerateCRC(aiCRC, "Owner8cfb00", 0);
        return aiCRC;
    }();
    return uiclassType;

}
