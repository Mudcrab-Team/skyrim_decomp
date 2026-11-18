// Source exposure: mixed (target listing, public declarations, sibling hint).
// Origin: public declarations and anonymous sibling code.
// TESConditionItem::Copy: SIBLING(fo4-private@1b765c70, author-permission); adapted member copy.
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:91
// TESConditionItem, CONDITION_ITEM_DATA, FUNCTION_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations adapted from include/RE/T/TESCondition.h.
// Copy, TESParameters, TESForm: GUESS(low); names and signature remain unverified.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a7690 TESConditionItem::Copy
#include "TESConditionItem.h"
void TESConditionItem::Copy(const TESConditionItem* from, TESForm*)
{
    data.comparisonValue = from->data.comparisonValue;
    data.runOnRef = from->data.runOnRef;
    data.dataID = from->data.dataID;
    TESParameters::Copy(from->data.functionData, data.functionData);
    data.flags = from->data.flags;
    data.object = from->data.object;
}
