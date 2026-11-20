// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestOptimalLocation.cpp:76 (PathingRequestOptimalLocation::GetType)
// PathingRequestOptimalLocation, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
// 0x4f8cc0 PathingRequestOptimalLocation::GetType
#include "PathingRequestOptimalLocation.h"
unsigned int PathingRequestOptimalLocation::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestOptimalLocation", 0);
        return typeId;
    }
    return result;
}
