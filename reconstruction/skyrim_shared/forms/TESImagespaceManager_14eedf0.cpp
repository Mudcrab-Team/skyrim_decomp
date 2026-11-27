// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x14eedf0 TESImagespaceManager::IsScreenshotSaved
#include "TESImagespaceManager_14eedf0.h"

bool TESImagespaceManager::IsScreenshotSaved()
{
    return unk211 || unk218 != nullptr;
}
