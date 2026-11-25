// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/PackageList.cpp:501
// PackageList, PackageList::VisitPackages: SIBLING(fo4-private@1b765c70, author-permission)
// PackageList::IPackageVisitor, PackageList::IPackageVisitor::VisitPackage, PackageList::listPackages: GUESS(medium); names from the sibling body, declared outside the permitted folders
// BSContainer, BSContainer::ForEachResult, BSContainer::ForEachResult::kStop, BSContainer::ForEachResult::kContinue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSSimpleListNode, BSSimpleListNode::item, BSSimpleListNode::next: GUESS(low); stand-in for the sibling list type
// TESPackage: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class TESPackage;

namespace BSContainer
{
    enum class ForEachResult
    {
        kStop = 0,
        kContinue = 1
    };
}

struct BSSimpleListNode
{
    TESPackage* item;       // 00
    BSSimpleListNode* next; // 08
};

class PackageList
{
public:
    struct IPackageVisitor
    {
        virtual BSContainer::ForEachResult VisitPackage(TESPackage* a_package) = 0;  // 00
    };

    void VisitPackages(IPackageVisitor& a_visitor) const;

    BSSimpleListNode listPackages;  // 00
};
static_assert(sizeof(PackageList) == 0x10, "PackageList size");
