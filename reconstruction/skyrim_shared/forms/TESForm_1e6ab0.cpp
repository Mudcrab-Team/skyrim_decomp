// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: statement shape adapted from a sibling body, offsets and names checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1e6ab0 TESForm::BelongsInGroup
// Adapted bodies: TESForm::BelongsInGroup from the Fallout 3 decompilation (null check, tag, status and type comparison, bool result); names are not taken
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00440000_o2.cpp:22759
#include "TESForm_1e6ab0.h"

// A group header belongs to this form type when it is a top-level group whose label is this type's code.
bool TESForm::BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly)
{
    bool result = false;
    if (a_form && a_form->form == formEnumString[2].formCode && a_form->formID == 0 &&
        a_form->flags == formEnumString[formType].formCode) {
        result = true;
    }
    return result;
}
