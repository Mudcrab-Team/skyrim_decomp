// Source exposure: mixed (community headers; CrashLogger layout; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSNamedPackageData.cpp:18
// 0x44bcd0 BGSPackageDataList::GetByUID
// Adapted bodies: BGSPackageDataList::GetByUID from the sibling source named above
#include "BGSPackageDataList_44bcd0.h"

IPackageData* BGSPackageDataList::GetByUID(unsigned char a_uid) const
{
    IPackageData* result = nullptr;
    for (unsigned int i = 0; i < dataSize; ++i) {
        if (uids[i] == a_uid) {
            result = data[i];
            i = dataSize;
        }
    }
    return result;
}
