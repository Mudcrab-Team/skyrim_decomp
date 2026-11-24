// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadGlobalData.cpp:787
// 0x61cf40 BGSSaveLoadGlobalData::RevertGlobalDataRange
// Adapted bodies: BGSSaveLoadGlobalData::RevertGlobalDataRange from the sibling source named above
#include "BGSSaveLoadGlobalData_61cf40.h"

void BGSSaveLoadGlobalData::RevertGlobalDataRange(unsigned int a_start, unsigned int a_end, bool a_fullRevert)
{
    BGSLoadGameBuffer buffer;
    for (; a_start < a_end; ++a_start)
        RevertGlobalData(a_start, &buffer, a_fullRevert);
}
