// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0x186fd0 ??0ExtraFollowerSwimBreadcrumbs@@QEAA@XZ
// 0x186fd0 ExtraFollowerSwimBreadcrumbs::ExtraFollowerSwimBreadcrumbs
#include "ExtraFollowerSwimBreadcrumbs_186fd0.h"

ExtraFollowerSwimBreadcrumbs::ExtraFollowerSwimBreadcrumbs()
    : BSExtraData()
    , leaderState(0)
    , leaderLocation(gZeroPoint)
    , leaderNavMeshID(0)
{
    crumbs.item = 0;
    crumbs.nextNode = nullptr;
}
