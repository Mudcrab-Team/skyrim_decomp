// Source exposure: mixed (target listing, public declarations, sibling hint).
// Origin: public declarations and anonymous sibling code.
// TESConditionItem::Copy: SIBLING(fo4-private@1b765c70, author-permission); adapted member copy.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:91
// TESConditionItem, CONDITION_ITEM_DATA, FUNCTION_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations adapted from include/RE/T/TESCondition.h.
// Copy, TESParameters, TESForm: GUESS(low); names and signature remain unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a7a30 TESConditionItem::GetComparisonValue
#include "TESConditionItem_4a7a30.h"

float TESConditionItem::GetComparisonValue() const
{
    if (TestBit(data.flags, 2)) {
        return data.comparisonValue.global ? data.comparisonValue.global->value : 0.0f;
    }
    return data.comparisonValue.value;
}
