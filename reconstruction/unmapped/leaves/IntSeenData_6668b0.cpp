// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Misc/SeenData.cpp:249
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout/misc/seendata.cpp:495
// 0x6668b0 IntSeenData::~IntSeenData
// Adapted bodies: IntSeenData::~IntSeenData from the sibling sources named above
#include "IntSeenData_6668b0.h"

IntSeenData::~IntSeenData()
{
    delete pNextSection;
}
