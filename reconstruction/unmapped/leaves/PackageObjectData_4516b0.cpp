// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageDataObjectList.cpp:240
// 0x4516b0 PackageObjectData::Assign
// Adapted bodies: BGSPackageDataObjectList::Copy from the sibling source named above
#include "PackageObjectData_4516b0.h"

void PackageObjectData::Assign(const IPackageData* a_other)
{
    BGSPackageDataObjectList* source = dynamic_cast<BGSPackageDataObjectList*>(const_cast<IPackageData*>(a_other));
    if (source) {
        source->array.CopyTo(array);
        radius = source->radius;
    }
}
