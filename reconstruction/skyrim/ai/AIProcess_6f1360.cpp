// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6f1360 AIProcess::SetLastSeenPosition
// Adapted bodies: none
#include "AIProcess_6f1360.h"

void AIProcess::SetLastSeenPosition(const NiPoint3& a_position)
{
    if (high) {
        MiddleHighProcessData* data = middleHigh;
        data->lastSeenPosition.x = a_position.x;
        data->lastSeenPosition.y = a_position.y;
        data->lastSeenPosition.z = a_position.z;
    }
}
