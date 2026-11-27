// CI hash: 0x558d80 ?Function558d80@MapCamera@@QEAAXMMM@Z
// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// MapCamera: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// MapCamera::Function558d80: GUESS(low)
// MapCamera::positionX, MapCamera::positionY, MapCamera::positionZ: GUESS(low)
// 0x558d80 MapCamera::Function558d80
#include "MapCamera_558d80.h"

// Read or update the stored values.
void MapCamera::Function558d80(float x, float y, float z)
{
    positionX += x;
    positionY += y;
    positionZ += z;
}
