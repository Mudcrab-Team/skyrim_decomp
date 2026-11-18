// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFly.cpp:57
// 0x4f53c0 PathingRequestFly::GetType
#include "PathingRequestFly.h"
unsigned int PathingRequestFly::GetType() const {
    unsigned int result = PathingRequestFlyCRC;
    if (!result) {
        BSCRC32::GenerateCRC(PathingRequestFlyCRC, "PathingRequestFly", 0);
        return PathingRequestFlyCRC;
    }
    return result;
}
