// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0x4e3300 (skyrim_shared/pathfinding/PathingRequest): source copied, names replaced by placeholders.
// Origin: anonymous sibling and target listing.
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/PathingRequest.cpp:45
// 0x121a980 Owner121a980::Function121a980
#include "Owner121a980.h"

// guess: same compiled code as matched 0x4e3300 apart from relocated fields; its role here is not established.
unsigned int Owner121a980::Function121a980() const {
    unsigned int result = PathingRequestCRC;
    if (!result) {
        BSCRC32::GenerateCRC(PathingRequestCRC, "Owner121a980", 0);
        return PathingRequestCRC;
    }
    return result;
}
