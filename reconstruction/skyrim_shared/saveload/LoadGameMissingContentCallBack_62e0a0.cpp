// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-noeh.json
// Adapted bodies: none
// 0x62e0a0 LoadGameMissingContentCallBack::dtor_deleting
// CI hash: 0x62e0a0 ??_GLoadGameMissingContentCallBack@@UEAAPEAXI@Z
#include "LoadGameMissingContentCallBack_62e0a0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
LoadGameMissingContentCallBack::LoadGameMissingContentCallBack()
{
}

// Destroy the callback and delete its owned payload object if present.
LoadGameMissingContentCallBack::~LoadGameMissingContentCallBack()
{
    delete payload;
}
