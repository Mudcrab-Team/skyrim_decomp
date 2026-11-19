// Source exposure: mixed (pinned image listings and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the list layout follows CommonLibSSE-NG TESAIForm.h and BSTList.h.
// PackageList, AIDATA_GAME: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PackageNode, head, Function4a2ce0, CopyFrom: STANDIN GUESS(low)
// ClearPackageList, CopyPackageList: GUESS(low)
#pragma once

#include <cstdint>

class TESPackage;

// BSSimpleList::Node::item, BSSimpleList::Node::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct PackageNode
{
    TESPackage* item;
    PackageNode* next;
};

struct PackageList
{
    void Function4a2ce0();
    void CopyFrom(const PackageList& source);

    PackageNode head;
};
static_assert(sizeof(PackageList) == 0x10, "AI package list size");

// TESAIForm: EXE_RTTI
class TESAIForm
{
public:
    void ClearPackageList();
    void CopyPackageList(const TESAIForm& source);

private:
    // aiData, aiPackages: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t padding00[8];
    std::uint8_t aiData[0xC];
    PackageList aiPackages;
};
