// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSFeaturedItemMessage.cpp:51
// 0x1dba20 BGSSkinForm::GetSkin
#include "BGSSkinForm_1dba20.h"

TESObjectARMO* BGSSkinForm::GetSkin(TESForm* a_form)
{
    BGSSkinForm* skinForm = dynamic_cast<BGSSkinForm*>(a_form);
    if (skinForm)
        return skinForm->skin;
    return nullptr;
}
