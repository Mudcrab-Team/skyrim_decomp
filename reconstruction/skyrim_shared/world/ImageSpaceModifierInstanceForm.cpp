// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations only
// 0x2a3650 ImageSpaceModifierInstanceForm::Unk_25
// Adapted bodies: none
#include "ImageSpaceModifierInstanceForm.h"

bool ImageSpaceModifierInstanceForm::Unk_25()
{
    if (imod) {
        return imod->Function2a7630(age);
    }
    return false;
}
