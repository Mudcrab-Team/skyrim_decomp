// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestHide.cpp:58
// 0x4f7cf0 PathingRequestHide::GetType
#include "PathingRequestHide.h"
unsigned int PathingRequestHide::GetType() const {
    unsigned int result = PathingRequestHideCRC;
    if (!result) {
        BSCRC32::GenerateCRC(PathingRequestHideCRC, "PathingRequestHide", 0);
        return PathingRequestHideCRC;
    }
    return result;
}
