// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESContainer.cpp:78
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1e0000 TESContainer::~TESContainer
// CI hash: 0x1e0000 ??1TESContainer@@UEAA@XZ
#include "TESContainer_1e0000.h"

TESContainer::~TESContainer()
{
    FreeObjectList();
}
