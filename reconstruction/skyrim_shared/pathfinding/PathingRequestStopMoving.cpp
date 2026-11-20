// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestStopMoving.cpp:17 (PathingRequestStopMoving::GetType)
// PathingRequestStopMoving, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
// 0x4f9670 PathingRequestStopMoving::GetType
#include "PathingRequestStopMoving.h"
unsigned int PathingRequestStopMoving::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestStopMoving", 0);
        return typeId;
    }
    return result;
}
