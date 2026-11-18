// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/PathingRequest.cpp:45
// 0x4e3300 PathingRequest::GetType
#include "PathingRequest.h"
unsigned int PathingRequest::GetType() const {
    unsigned int result = PathingRequestCRC;
    if (!result) {
        BSCRC32::GenerateCRC(PathingRequestCRC, "PathingRequest", 0);
        return PathingRequestCRC;
    }
    return result;
}
