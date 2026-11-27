// Source exposure: mixed (community headers; CrashLogger layout; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSNamedPackageData.cpp:11
// 0x44b9e0 BGSPackageDataList::InitItems
// Adapted bodies: BGSPackageDataList::InitItems from the sibling source named above
#include "BGSPackageDataList_44b9e0.h"

void BGSPackageDataList::InitItems(TESForm* a_owner)
{
    for (unsigned int i = 0; i < dataSize; ++i)
        data[i]->InitPackage(a_owner);
}
