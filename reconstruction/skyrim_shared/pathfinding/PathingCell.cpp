// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/PathingCell.cpp:62 (PathingCell::GetType)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyHover.cpp:45 (PathingRequestFlyHover::GetType; CRC initialization pattern)
// PathingCell, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
// 0x4e0020 PathingCell::GetType
#include "PathingCell.h"
unsigned int PathingCell::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingCell", 0);
        return typeId;
    }
    return result;
}
