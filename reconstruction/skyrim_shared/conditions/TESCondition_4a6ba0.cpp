// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a6ba0 TESCondition::Compare
// Adapted bodies: TESCondition::Compare from fo4-private@1b765c70 src/Shared/AI/TESCondition.cpp:210 (see the header)
#include "TESCondition_4a6ba0.h"

bool TESCondition::Compare(const TESCondition* a_other) const
{
    TESConditionItem* compare = a_other->head;
    TESConditionItem* item = head;
    bool differs = false;
    if (compare)
    {
        while (compare && !differs)
        {
            if (!item || (differs = compare->Compare(item)))
                differs = true;
            if (item)
                item = item->next;
            compare = compare->next;
        }
        if (differs)
            return true;
    }
    if (!item)
        return false;
    return true;
}
