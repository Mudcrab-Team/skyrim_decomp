// Source exposure: mixed (community declarations and pinned image analysis).
// Code origin: original reconstruction from the pinned image; declarations as labelled.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x239820 InventoryChanges::GetEquippedArmorInSlot
// InventoryChanges::GetEquippedArmorInSlot: CRASHLOGGER_PDB(59818@2026.10.24)
// GetArmorInSlotFunctor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); class name from its vtable declaration
// GetArmorInSlotFunctor::GetArmorInSlotFunctor, GetArmorInSlotFunctor::~GetArmorInSlotFunctor, GetArmorInSlotFunctor::slot, GetArmorInSlotFunctor::armor: GUESS(low); observed local visitor fields and overrides
// InventoryChanges, InventoryChanges::IItemChangeVisitor, InventoryChanges::VisitWornItems: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IItemChangeVisitor::~IItemChangeVisitor, IItemChangeVisitor::Visit, IItemChangeVisitor::ShouldVisit, IItemChangeVisitor::Unk_03: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InventoryEntryData, TESBoundObject, BGSKeyword, TESObjectARMO: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetArmorInSlotFunctor::Visit: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
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
    TESObjectARMO* GetEquippedArmorInSlot(std::int32_t slot);
    void VisitWornItems(IItemChangeVisitor&);
};

class GetArmorInSlotFunctor : public InventoryChanges::IItemChangeVisitor
{
public:
    explicit GetArmorInSlotFunctor(std::int32_t value) : slot(value - 30), armor(nullptr) {}
    ~GetArmorInSlotFunctor() override {}
    std::uint32_t Visit(InventoryEntryData*) override;
    std::int32_t slot;  // 08
    TESObjectARMO* armor;  // 10
};
