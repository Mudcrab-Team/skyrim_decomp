// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x1246150 PathFollowerStateFollowPathToParameter::Func3_14112E310
#include "PathFollowerStateFollowPathToParameter_1246150.h"

// Reads the three float parameters and target identifier, then resolves and stores the target pointer.
void PathFollowerStateFollowPathToParameter::Func3_14112E310(PathFollowerReader* reader, PathFollowerTargetLookup* lookup)
{
    reader->ReadFloat(&param08);
    reader->ReadFloat(&param0C);
    reader->ReadFloat(&param10);
    std::uint32_t id = 0xFFFFFFFFu;
    reader->ReadUInt32(&id);
    target18 = lookup->LookupTarget(id);
}
