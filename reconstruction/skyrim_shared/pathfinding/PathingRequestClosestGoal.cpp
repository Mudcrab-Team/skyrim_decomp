// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestClosestGoal.cpp:34 (PathingRequestClosestGoal::GetType)
// PathingRequestClosestGoal, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
// 0x4f2990 PathingRequestClosestGoal::GetType
#include "PathingRequestClosestGoal.h"
unsigned int PathingRequestClosestGoal::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestClosestGoal", 0);
        return typeId;
    }
    return result;
}
