// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6ff0a0 AIProcess::GetHeadtrackTarget
// Adapted bodies: none
#include "AIProcess_6ff0a0.h"

ObjectRefHandle AIProcess::GetHeadtrackTarget(std::int32_t a_type) const
{
    return high ? high->headTrackTarget[a_type] : g_nullRefHandle;
}
