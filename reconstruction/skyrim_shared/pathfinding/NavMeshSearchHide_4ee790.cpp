// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json
// Adapted bodies: none
// 0x4ee790 NavMeshSearchHide::dtor_deleting
// CI hash: 0x4ee790 ??_GNavMeshSearchHide@@UEAAPEAXI@Z
#include "NavMeshSearchHide_4ee790.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NavMeshSearchHide::NavMeshSearchHide()
{
}

// Destroy NavMeshSearchHide and invoke the base search destructor.
NavMeshSearchHide::~NavMeshSearchHide()
{
}
