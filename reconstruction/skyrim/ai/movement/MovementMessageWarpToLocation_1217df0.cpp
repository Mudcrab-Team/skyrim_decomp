// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json
// Adapted bodies: none
// 0x1217df0 MovementMessageWarpToLocation::dtor_deleting
// CI hash: 0x1217df0 ??_GMovementMessageWarpToLocation@@UEAAPEAXI@Z
#include "MovementMessageWarpToLocation_1217df0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
MovementMessageWarpToLocation::MovementMessageWarpToLocation()
{
}

// Destroy the warp-to-location movement message and its location member.
MovementMessageWarpToLocation::~MovementMessageWarpToLocation()
{
}
