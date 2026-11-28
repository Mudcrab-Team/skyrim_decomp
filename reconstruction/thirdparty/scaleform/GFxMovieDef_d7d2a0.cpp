// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json
// Adapted bodies: none
// 0xd7d2a0 GFxMovieDef::dtor
// CI hash: 0xd7d2a0 ??_GGFxMovieDef@@UEAAPEAXI@Z
#include "GFxMovieDef_d7d2a0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
GFxMovieDef::GFxMovieDef()
{
}

// Destroy GFxMovieDef and restore base vftables.
GFxMovieDef::~GFxMovieDef()
{
}
