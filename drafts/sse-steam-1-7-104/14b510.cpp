// Near miss: 75.0% | control-flow
// 0x14b510 EffectSetting::HasKeyword
// Code origin: original reconstruction from local binary analysis; source leads as labelled below.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EffectSetting, HasKeyword, BGSKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HasKeyword: SIBLING(fo4-private@1b765c70, author-permission); control-flow lead, independently written for this target
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EffectSetting.cpp:211
#include "include/14b510/EffectSetting_14b510.h"

bool EffectSetting::HasKeyword(const BGSKeyword* keyword) const
{
    bool found = BGSKeywordForm::HasKeyword(keyword);
    if (!found && archetypeInfo[data.archetype].associatedFormType == 4) {
        TESForm* form = data.associatedForm;
        const BGSKeyword* associated = nullptr;
        if (form && form->formType == 4)
            associated = static_cast<const BGSKeyword*>(form);
        return keyword == associated;
    }
    return found;
}
