// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESLeveledList.cpp:118
// 0x1e8810 TESLeveledList::~TESLeveledList
// CI hash: 0x1e8810 ??1TESLeveledList@@UEAA@XZ
#include "TESLeveledList_1e8810.h"

TESLeveledList::~TESLeveledList()
{
    FreeLeveledList();
}
