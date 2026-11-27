// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSAIGuardUtils.cpp:44
// CheckSuspicionsVsFormList, CheckSuspicionsVsForm: SIBLING(fo4-private@1b765c70, author-permission)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSContainer::ForEachResult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN OBSERVED; NG numbers kContinue 0 and kStop 1, the listing returns 0 to stop and 1 to continue
// TESForm, Actor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; opaque
// CheckSuspicionsVsFormList::actor, CheckSuspicionsVsFormList::suspicious: GUESS(low); the operator body is adapted from the sibling
#pragma once

class TESForm;
class Actor;

namespace BSContainer
{
    enum class ForEachResult
    {
        kStop = 0,
        kContinue = 1
    };
}

namespace GuardUtils
{
    bool CheckSuspicionsVsForm(TESForm* a_form, Actor& a_actor);

    class CheckSuspicionsVsFormList
    {
    public:
        BSContainer::ForEachResult operator()(TESForm* a_form);

        Actor& actor;     // 00
        bool suspicious;  // 08
    };
}
