// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a55a0 ImageSpaceModifierInstanceForm::dtor_deleting
// CI hash: 0x2a55a0 ??_GImageSpaceModifierInstanceForm@@UEAAPEAXI@Z
#include "ImageSpaceModifierInstanceForm_2a55a0.h"

ImageSpaceModifierInstanceForm::ImageSpaceModifierInstanceForm()
{
}

ImageSpaceModifierInstanceForm::~ImageSpaceModifierInstanceForm()
{
    unk40 = nullptr;
    if (g_currentFormInstance == this)
    {
        g_currentFormInstance = nullptr;
    }
    if (g_secondFormInstance == this)
    {
        g_secondFormInstance = nullptr;
    }
}
