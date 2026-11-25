// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESSpellList.cpp:10
// 0x1f0a90 TESSpellList::~TESSpellList
// CI hash: 0x1f0a90 ??1TESSpellList@@UEAA@XZ
#include "TESSpellList_1f0a90.h"

TESSpellList::~TESSpellList()
{
    FreeSpellList();
}
