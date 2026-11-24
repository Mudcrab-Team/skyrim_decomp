// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4f47f0 PathingCoverLocation::Write
// Adapted bodies: PathingCoverLocation::Write from the sibling source named in the header
#include "PathingCoverLocation_4f47f0.h"

void PathingCoverLocation::Write(BSPathingStreamWrite& a_stream) const
{
    BSPathingLocation::Write(a_stream);
    a_stream.DoWriteFloat(LeftVertex.x);
    a_stream.DoWriteFloat(LeftVertex.y);
    a_stream.DoWriteFloat(LeftVertex.z);
    a_stream.DoWriteFloat(RightVertex.x);
    a_stream.DoWriteFloat(RightVertex.y);
    a_stream.DoWriteFloat(RightVertex.z);
    a_stream.DoWriteFloat(EdgeDirection.x);
    a_stream.DoWriteFloat(EdgeDirection.y);
    a_stream.DoWriteFloat(EdgeDirection.z);
    a_stream.DoWriteUChar(cCoverHeight);
    a_stream.DoWriteBool(bStandCover);
    a_stream.DoWriteBool(bHigherThanCrouch);
    a_stream.DoWriteBool(bLeftEdgeOpen);
    a_stream.DoWriteBool(bRightEdgeOpen);
    a_stream.DoWriteUChar(cEdge);
    a_stream.DoWriteUChar(cState);
}
