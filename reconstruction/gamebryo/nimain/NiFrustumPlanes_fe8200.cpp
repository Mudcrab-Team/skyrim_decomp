// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// NiFrustumPlanes, NiPlane, NiPoint3, cullingPlanes, activePlanes, basePlaneStates, unk68 and unk6C: CRASHLOGGER_PDB(59818@2026.10.24)
// CI hash: 0xfe8200 ??4NiFrustumPlanes@@QEAAAEAU0@AEBU0@@Z
// 0xfe8200 NiFrustumPlanes::operator=
#include "NiFrustumPlanes_fe8200.h"

NiFrustumPlanes& NiFrustumPlanes::operator=(const NiFrustumPlanes& other)
{
    CopyFrom(other);
    return *this;
}
