// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a2ff0 PackageList::VisitPackages
// Adapted bodies: PackageList::VisitPackages from fo4-private@1b765c70 src/Shared/AI/PackageList.cpp:501 (see the header)
#include "PackageList_4a2ff0.h"

void PackageList::VisitPackages(IPackageVisitor& a_visitor) const
{
    const PackageList* list = this;
    TESPackage* package;
    do
    {
        if (!list)
            break;
        package = list->listPackages.item;
        if (!package)
            break;
        list = reinterpret_cast<const PackageList*>(list->listPackages.next);
    } while (a_visitor.VisitPackage(package) == BSContainer::ForEachResult::kContinue);
}
