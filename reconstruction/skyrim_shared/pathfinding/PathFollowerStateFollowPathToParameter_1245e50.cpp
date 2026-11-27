// CI hash: 0x1245e50 ?Function1245e50@PathFollowerStateFollowPathToParameter@@QEAAXPEAXMMM0@Z
// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// PathFollowerStateFollowPathToParameter: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PathFollowerStateFollowPathToParameter::Function1245e50: GUESS(low)
// PathFollowerStateFollowPathToParameter::x, PathFollowerStateFollowPathToParameter::y, PathFollowerStateFollowPathToParameter::z, PathFollowerStateFollowPathToParameter::storedData: GUESS(low)
// 0x1245e50 PathFollowerStateFollowPathToParameter::Function1245e50
#include "PathFollowerStateFollowPathToParameter_1245e50.h"

// Read or update the stored values.
void PathFollowerStateFollowPathToParameter::Function1245e50(void* context, float first, float second, float third, void* data)
{
    z = third;
    storedData = data;
    x = first;
    y = second;
}
