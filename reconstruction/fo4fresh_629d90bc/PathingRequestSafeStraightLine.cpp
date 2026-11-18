// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: anonymous sibling and target listing.
// GetType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestSafeStraightLine.cpp:41
// 0x4f93a0 PathingRequestSafeStraightLine::GetType
#include "PathingRequestSafeStraightLine.h"
unsigned int PathingRequestSafeStraightLine::GetType() const {
    unsigned int result = PathingRequestSafeStraightLineCRC;
    if (!result) {
        BSCRC32::GenerateCRC(PathingRequestSafeStraightLineCRC, "PathingRequestSafeStraightLine", 0);
        return PathingRequestSafeStraightLineCRC;
    }
    return result;
}
