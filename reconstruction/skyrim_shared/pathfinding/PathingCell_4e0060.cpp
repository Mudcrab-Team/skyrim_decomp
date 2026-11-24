// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4e0060 PathingCell::Write
// Adapted bodies: PathingCell::Write from the sibling source named in the header
#include "PathingCell_4e0060.h"

void PathingCell::Write(BSPathingStreamWrite& a_stream) const
{
    a_stream.DoWriteNumericID(Info.WorldSpaceID);
    if (Info.WorldSpaceID) {
        a_stream.DoWriteUInt(Info.CellID);
    } else {
        a_stream.DoWriteNumericID(Info.CellID);
    }
}
