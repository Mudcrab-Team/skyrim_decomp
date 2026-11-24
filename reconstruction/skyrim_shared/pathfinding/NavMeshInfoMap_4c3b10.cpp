// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x4c3b10 NavMeshInfoMap::~NavMeshInfoMap
// Adapted bodies: NavMeshInfoMap::~NavMeshInfoMap follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/navmeshinfomap.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/navmeshinfomap.cpp:539
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/navmeshinfomap.cpp:425
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/NavMeshInfo/NavMeshInfoMap.cpp:35
#include "NavMeshInfoMap_4c3b10.h"

NavMeshInfoMap::~NavMeshInfoMap()
{
    ClearNavMeshInfoMaps();
}
