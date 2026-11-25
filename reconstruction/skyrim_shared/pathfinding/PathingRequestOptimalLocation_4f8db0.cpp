// Source exposure: mixed (target observations; permitted sibling naming hints).
// Code origin: original; target call and field observations
// SPDX-License-Identifier: CC0-1.0
// 0x4f8db0 PathingRequestOptimalLocation::Read
// Adapted bodies: none
#include "PathingRequestOptimalLocation_4f8db0.h"

void PathingRequestOptimalLocation::Read(BSPathingStreamRead& stream)
{
    PathingRequest::Read(stream);
    stream.DoReadFloat(fMinDistance);
    stream.DoReadFloat(fMaxDistance);
    stream.DoReadFloat(fAbsoluteMinDistance);
    stream.DoReadFloat(fAbsoluteMaxDistance);
}
