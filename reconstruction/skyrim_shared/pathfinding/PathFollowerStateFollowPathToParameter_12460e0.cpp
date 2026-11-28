// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x12460e0 PathFollowerStateFollowPathToParameter::Func2_14112E2A0
#include "PathFollowerStateFollowPathToParameter_12460e0.h"

// Writes the three float parameters and the resolved target identifier to the stream writer.
void PathFollowerStateFollowPathToParameter::Func2_14112E2A0(PathFollowerWriter* writer, PathFollowerIdResolver* resolver)
{
    writer->WriteFloat(param08);
    writer->WriteFloat(param0C);
    writer->WriteFloat(param10);
    std::uint32_t id = resolver->ResolveId(target18);
    writer->WriteUInt32(id);
}
