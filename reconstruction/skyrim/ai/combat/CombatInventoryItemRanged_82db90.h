// Source exposure: mixed (community headers; compared functions from the pinned image; a permitted sibling).
// Code origin: declarations and body shape adapted from a permitted sibling, offsets and call targets checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatInventoryItemRanged: EXE_RTTI
// CombatInventoryItemComposite::LoadGame: SIBLING(fo4-private@1b765c70, author-permission)
// CombatInventoryItemRanged::LoadGame: GUESS(low); the override that reads the two range limits after the composite state
// CombatInventoryItem, CombatInventoryItem::LoadGame, CombatInventoryItemComposite, BGSLoadGameBuffer, BGSLoadGameBuffer::LoadDataEndian: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); header-gap CombatInventoryItem, CombatInventoryItemComposite
// BGSLoadGameBuffer::ReadFormID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission) OBSERVED; reads a form id into the reference, the result is not used here
// TESForm, TESForm::LookupByID: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CombatInventoryItemComposite::secondaryItem, CombatInventoryItemRanged::minRange, CombatInventoryItemRanged::maxRange, unknown08: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:161
#pragma once

#include <cstdint>

class TESForm
{
public:
    static TESForm* LookupByID(std::uint32_t a_formID);
};

class BGSLoadGameBuffer
{
public:
    bool ReadFormID(std::uint32_t& a_formID);
    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);
};

class CombatInventoryItem
{
public:
    virtual void LoadGame(BGSLoadGameBuffer* a_buf);

    std::uint8_t unknown08[0x28];  // 08
};
static_assert(sizeof(CombatInventoryItem) == 0x30, "CombatInventoryItem size");

class CombatInventoryItemComposite : public CombatInventoryItem
{
public:
    // Loads the base item, then resolves the stored form id of the secondary item.
    void LoadGame(BGSLoadGameBuffer* a_buf) override
    {
        CombatInventoryItem::LoadGame(a_buf);
        std::uint32_t formID = 0;
        a_buf->ReadFormID(formID);
        secondaryItem = TESForm::LookupByID(formID);
    }

    TESForm* secondaryItem;  // 30
};

class CombatInventoryItemRanged : public CombatInventoryItemComposite
{
public:
    void LoadGame(BGSLoadGameBuffer* a_buf) override;

    float minRange;  // 38
    float maxRange;  // 3C
};
