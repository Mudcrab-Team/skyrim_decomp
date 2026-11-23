// Source exposure: binary-analysis (the pinned image listing), community-headers.
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5d53a0 SpellItem::Function5d53a0
// Adapted bodies: none
#include "SpellItem_5d53a0.h"

bool SpellItem::Function5d53a0(MagicItem* a_item, uint32_t a_flag)
{
    if (!a_item) {
        return false;
    }

    switch (a_item->GetSpellType()) {
    case 0:
    case 3:
    case 5:
        break;
    case 6:
    case 12:
        if (a_item->GetCastingType() == 0 || a_flag == 3) {
            return false;
        }
        break;
    default:
        return false;
    }

    if (a_item->GetCastingType() == 2) {
        return true;
    }

    return false;
}
