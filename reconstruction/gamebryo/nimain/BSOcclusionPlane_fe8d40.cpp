// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionPlane, CopyFrustumPlanes, BuildFrustumPlanes, NiPoint3 and frustumPlanes: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfe8d40 BSOcclusionPlane::CopyFrustumPlanes
// CI hash: 0xfe8d40 ?CopyFrustumPlanes@BSOcclusionPlane@@QEAAXAEBUNiPoint3@@AEAUNiFrustumPlanes@@@Z
#include "BSOcclusionPlane_fe8d40.h"

void BSOcclusionPlane::CopyFrustumPlanes(const NiPoint3& position, NiFrustumPlanes& result)
{
    BuildFrustumPlanes(position);
    result.CopyFrom(frustumPlanes);
}
