// CI hash: 0x1246b70 ?Function1246b70@PathFollowerStateKeepLastDirection@@QEAAXPEAXAEBUDirection1246b70@@M0@Z
// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// PathFollowerStateKeepLastDirection: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PathFollowerStateKeepLastDirection::Function1246b70: GUESS(low)
// PathFollowerStateKeepLastDirection::x, PathFollowerStateKeepLastDirection::y, PathFollowerStateKeepLastDirection::z, PathFollowerStateKeepLastDirection::value, PathFollowerStateKeepLastDirection::storedData, Direction1246b70: GUESS(low)
// 0x1246b70 PathFollowerStateKeepLastDirection::Function1246b70
#include "PathFollowerStateKeepLastDirection_1246b70.h"

// Read or update the stored values.
void PathFollowerStateKeepLastDirection::Function1246b70(void* context, const Direction1246b70& direction, float parameter, void* data)
{
    x = direction.x;
    y = direction.y;
    z = direction.z;
    storedData = data;
    value = parameter;
}
