// Source exposure: mixed (community headers; CrashLogger layout; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSNamedPackageData.cpp:121
// 0x44ca00 BGSPackageDataList::FindData
// Adapted bodies: BGSPackageDataList::FindData from the sibling source named above
#include "BGSPackageDataList_44ca00.h"

unsigned int BGSPackageDataList::FindData(const IPackageData* a_data) const
{
    unsigned int found = static_cast<unsigned int>(-1);
    for (unsigned int i = 0; i < dataSize; ++i) {
        if (data[i] == a_data) {
            found = i;
            i = dataSize;
        }
    }
    return found;
}
