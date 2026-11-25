// Source exposure: mixed (community declarations and pinned image analysis).
// Code origin: original reconstruction from the pinned image; declarations as labelled.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2397c0 InventoryChanges::GetWornApparelCountWithKeyword
// Adapted bodies: none
#include "InventoryChanges_2397c0.h"

std::uint32_t InventoryChanges::GetWornApparelCountWithKeyword(BGSKeyword* keyword)
{
    if (keyword) {
        CountObjectsWithKeywordFunctor visitor(keyword);
        VisitWornItems(visitor);
        return visitor.count;
    }
    return 0;
}
