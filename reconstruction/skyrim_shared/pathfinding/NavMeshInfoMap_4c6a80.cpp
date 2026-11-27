// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4c6a80 NavMeshInfoMap::Visit
// Adapted bodies: none
#include "NavMeshInfoMap_4c6a80.h"

void NavMeshInfoMap::Visit()
{
    MapVisitor visitor;
    target.Accept(&visitor);
}
