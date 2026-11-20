// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::GetInventoryChanges: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// The FormType overload follows the existing reconstruction declaration.
// extraList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
    InventoryChanges* GetInventoryChanges(FormType) const;

private:
    std::uint8_t padding00[0x70];
    ExtraDataList extraList;
};
