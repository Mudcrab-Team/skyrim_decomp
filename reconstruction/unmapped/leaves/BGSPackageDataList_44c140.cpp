// Source exposure: mixed (community headers; CrashLogger layout; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSNamedPackageData.cpp:85
// 0x44c140 BGSPackageDataList::GetUIDForData
// Adapted bodies: BGSPackageDataList::GetUIDForData from the sibling source named above
#include "BGSPackageDataList_44c140.h"

unsigned char BGSPackageDataList::GetUIDForData(const IPackageData* a_data) const
{
    unsigned int size = dataSize;
    unsigned int found = static_cast<unsigned int>(-1);
    for (unsigned int i = 0; i < size; ++i) {
        if (data[i] == a_data) {
            found = i;
            i = size;
        }
    }
    if (found < size)
        return uids[found];
    return static_cast<unsigned char>(-1);
}
