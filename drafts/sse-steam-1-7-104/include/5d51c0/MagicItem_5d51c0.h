// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicItem::GetCostActorValue: CRASHLOGGER_PDB(59818@2026.10.24)
// MagicItem, GetSpellType, GetCastingType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicItemVTable, vtable, slots: STANDIN OBSERVED

#pragma once
#include <cstdint>
class MagicItem;
struct MagicItemVTable
{
    void* slots[83];
    std::int32_t (*GetSpellType)(const MagicItem*);
    void* setCastingType;
    std::uint32_t (*GetCastingType)(const MagicItem*);
};
class MagicItem
{
public:
    MagicItemVTable* vtable;
    std::int32_t GetCostActorValue(std::uint32_t castingSource) const;
};
