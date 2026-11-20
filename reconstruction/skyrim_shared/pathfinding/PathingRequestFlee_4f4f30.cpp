// Source exposure: binary-analysis.
// Code origin: original reconstruction of request copying, stream calls and option updates.
// 0x4f4f30 PathingRequestFlee::CopyMembers
// 0x4f4ff0 PathingRequestFlee::Save
// 0x4f5030 PathingRequestFlee::Load
// 0x71f990 PathingRequestFlee::CopyOptions
#include "PathingRequestFlee_4f4f30.h"

void PathingRequestFlee::CopyMembers(PathingRequestFlee& destination) const
{
    PathingRequest::CopyMembers(destination);
    destination.retreatDistance = retreatDistance;
}

void PathingRequestFlee::Save(PathingWriter& stream) const
{
    PathingRequest::Save(stream);
    stream.WriteFloat(retreatDistance);
}

void PathingRequestFlee::Load(PathingReader& stream)
{
    PathingRequest::Load(stream);
    stream.ReadFloat(retreatDistance);
}

void PathingRequestFlee::CopyOptions(const PathingOptions& source)
{
    const auto requestFlags = options.requestFlags;
    options.CopyFrom(source);
    options.requestFlags = requestFlags;
}
