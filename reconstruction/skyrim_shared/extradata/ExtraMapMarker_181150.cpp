// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0x181150 ??1ExtraMapMarker@@UEAA@XZ
// 0x181150 ExtraMapMarker::~ExtraMapMarker
#include "ExtraMapMarker_181150.h"

// The CrashLogger name Create does not fit this body, which is written as what it does (a guess).
ExtraMapMarker::~ExtraMapMarker()
{
    delete mapData;
}
