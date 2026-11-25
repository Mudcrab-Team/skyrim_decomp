// Source exposure: mixed (community declarations and pinned image analysis).
// Code origin: original reconstruction from the pinned image; declarations as labelled.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2397c0 InventoryChanges::GetWornApparelCountWithKeyword
// InventoryChanges::GetWornApparelCountWithKeyword: SYMBOLS(tesv-2013-map)
// CountObjectsWithKeywordFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); class name from its vtable declaration
// CountObjectsWithKeywordFunctor::CountObjectsWithKeywordFunctor, CountObjectsWithKeywordFunctor::~CountObjectsWithKeywordFunctor, CountObjectsWithKeywordFunctor::keyword, CountObjectsWithKeywordFunctor::count, CountObjectsWithKeywordFunctor::formType: GUESS(low); observed local visitor fields and overrides
// InventoryChanges, InventoryChanges::IItemChangeVisitor, InventoryChanges::VisitWornItems: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IItemChangeVisitor::~IItemChangeVisitor, IItemChangeVisitor::Visit, IItemChangeVisitor::ShouldVisit, IItemChangeVisitor::Unk_03: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InventoryEntryData, TESBoundObject, BGSKeyword, TESObjectARMO: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CountObjectsWithKeywordFunctor::Visit: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once
#include <cstdint>

class InventoryEntryData;
class TESBoundObject;
class BGSKeyword;
class TESObjectARMO;

class InventoryChanges
{
public:
    class IItemChangeVisitor
    {
    public:
        virtual ~IItemChangeVisitor() {}
        virtual std::uint32_t Visit(InventoryEntryData*) = 0;
        virtual bool ShouldVisit(InventoryEntryData*, TESBoundObject*);
        virtual std::uint32_t Unk_03(InventoryEntryData*, void*, bool*);
    };
    std::uint32_t GetWornApparelCountWithKeyword(BGSKeyword* keyword);
    void VisitWornItems(IItemChangeVisitor&);
};

class CountObjectsWithKeywordFunctor : public InventoryChanges::IItemChangeVisitor
{
public:
    explicit CountObjectsWithKeywordFunctor(BGSKeyword* value) : keyword(value), count(0), formType(26) {}
    ~CountObjectsWithKeywordFunctor() override {}
    std::uint32_t Visit(InventoryEntryData*) override;
    BGSKeyword* keyword;  // 08
    std::uint32_t count;  // 10
    std::uint32_t formType;  // 14
};
