// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4c78b0 NavMeshInfoMap::~NavMeshInfoMap
// 0x4c4050 NavMeshInfoMap::SetAltered
#include "NavMeshInfoMap.h"
NavMeshInfoMap::NavMeshInfoMap() {}
NavMeshInfoMap::~NavMeshInfoMap() { ClearNavMap(this); }


