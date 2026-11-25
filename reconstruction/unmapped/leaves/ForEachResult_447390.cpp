// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSAIGuardUtils.cpp:44
// 0x447390 GuardUtils::CheckSuspicionsVsFormList::operator()
// Adapted bodies: GuardUtils::CheckSuspicionsVsFormList::operator() from the sibling source named above
#include "ForEachResult_447390.h"

BSContainer::ForEachResult GuardUtils::CheckSuspicionsVsFormList::operator()(TESForm* a_form)
{
    if (CheckSuspicionsVsForm(a_form, actor)) {
        suspicious = true;
        return BSContainer::ForEachResult::kStop;
    }
    return BSContainer::ForEachResult::kContinue;
}
