// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0x1818e0 ??0ExtraPackageStartLocation@@QEAA@PEAX0AEBUNiPoint3@@M@Z
// 0x1818e0 ExtraPackageStartLocation::ExtraPackageStartLocation
#include "ExtraPackageStartLocation_1818e0.h"

// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
ExtraPackageStartLocation::ExtraPackageStartLocation(void* a_loc1, void* a_loc2, const NiPoint3& a_pos, float a_rot)
    : BSExtraData()
{
    worldLoc.location = !a_loc1 ? a_loc2 : a_loc1;
    worldLoc.pos.x = a_pos.x;
    worldLoc.pos.y = a_pos.y;
    worldLoc.pos.z = a_pos.z;
    worldLoc.rot = a_rot;
}
