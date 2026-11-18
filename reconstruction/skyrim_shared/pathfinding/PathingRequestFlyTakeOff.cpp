// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyTakeOff.cpp:53 (PathingRequestFlyTakeOff::GetType)
// PathingRequestFlyTakeOff, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
// 0x4f7920 PathingRequestFlyTakeOff::GetType
#include "PathingRequestFlyTakeOff.h"
unsigned int PathingRequestFlyTakeOff::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestFlyTakeOff", 0);
        return typeId;
    }
    return result;
}
