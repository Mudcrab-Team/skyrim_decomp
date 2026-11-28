// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0x186320 ??1ExtraOcclusionPlaneRefData@@UEAA@XZ
// 0x186320 ExtraOcclusionPlaneRefData::~ExtraOcclusionPlaneRefData
#include "ExtraOcclusionPlaneRefData_186320.h"

ExtraOcclusionPlaneRefData::~ExtraOcclusionPlaneRefData()
{
    if (data) {
        delete data;
    }
    data = nullptr;
}
