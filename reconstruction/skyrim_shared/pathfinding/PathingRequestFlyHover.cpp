// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyHover.cpp:45 (PathingRequestFlyHover::GetType)
// PathingRequestFlyHover, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
// 0x4f6380 PathingRequestFlyHover::GetType
#include "PathingRequestFlyHover.h"
unsigned int PathingRequestFlyHover::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestFlyHover", 0);
        return typeId;
    }
    return result;
}
