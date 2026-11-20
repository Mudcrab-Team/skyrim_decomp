// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetInventoryChanges: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// InventoryChanges, ExtraDataList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

enum class FormType : std::uint8_t;
class InventoryChanges;
class ExtraDataList
{
public:
    InventoryChanges* GetInventoryChanges();
};

class TESObjectREFR
{
public:
    InventoryChanges* GetInventoryChanges(FormType type) const;
};
