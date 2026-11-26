// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a35b0 ImageSpaceModifierInstanceForm::ctor
#include "ImageSpaceModifierInstanceForm_2a35b0.h"

ImageSpaceModifierInstanceForm::ImageSpaceModifierInstanceForm(TESImageSpaceModifier* a_imod, float a_age, float a_strength, NiAVObject* a_target)
    : ImageSpaceModifierInstance(a_age, a_strength, a_target)
{
    unk30 = 0;
    unk38 = 0.0f;
    imod = a_imod;
    unk40 = 0;
    unk48 = 0;
    unk10 = 0;
}

ImageSpaceModifierInstanceForm::~ImageSpaceModifierInstanceForm()
{
}
