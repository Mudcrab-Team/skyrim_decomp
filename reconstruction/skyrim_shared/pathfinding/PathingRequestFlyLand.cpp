// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyLand.cpp:59
// 0x4f6e90 PathingRequestFlyLand::GetType
#include "PathingRequestFlyLand.h"
unsigned int PathingRequestFlyLand::GetType() const {
    unsigned int result = PathingRequestFlyLandCRC;
    if (!result) {
        BSCRC32::GenerateCRC(PathingRequestFlyLandCRC, "PathingRequestFlyLand", 0);
        return PathingRequestFlyLandCRC;
    }
    return result;
}
