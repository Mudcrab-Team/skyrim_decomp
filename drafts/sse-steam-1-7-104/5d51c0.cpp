// Near miss: 3.5 alignment distance | control-flow
// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x5d51c0 MagicItem::GetCostActorValue

#include "include/5d51c0/MagicItem_5d51c0.h"

std::int32_t MagicItem::GetCostActorValue(std::uint32_t castingSource) const
{
    const int zero_ = 0;
    if (this) {
        switch (static_cast<std::uint8_t>(vtable->GetSpellType(this))) {
        case 0:
        case 3:
        case 5:
            return 25;
        case 6:
        case 12:
            if (vtable->GetCastingType(this) != zero_) {
                return castingSource ? 64 : 82;
            }
            break;
        }
    }
    return -1;
}
