// Source exposure: mixed (target observations; permitted sibling naming/shape hints).
// Code origin: original; target call and field observations
// SPDX-License-Identifier: CC0-1.0
// 0x4f8d40 PathingRequestOptimalLocation::Write
// Adapted bodies: none
#include "PathingRequestOptimalLocation_4f8d40.h"

void PathingRequestOptimalLocation::Write(BSPathingStreamWrite& stream)
{
    PathingRequest::Write(stream);
    stream.DoWriteFloat(fMinDistance);
    stream.DoWriteFloat(fMaxDistance);
    stream.DoWriteFloat(fAbsoluteMinDistance);
    stream.DoWriteFloat(fAbsoluteMaxDistance);
}
