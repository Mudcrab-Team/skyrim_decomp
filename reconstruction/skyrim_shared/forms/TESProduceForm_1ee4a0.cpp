// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESProduceForm.cpp:48
// 0x1ee4a0 TESProduceForm::CopyComponent
#include "TESProduceForm_1ee4a0.h"

void TESProduceForm::CopyComponent(BaseFormComponent* a_rhs)
{
    TESProduceForm* copy = dynamic_cast<TESProduceForm*>(a_rhs);
    if (copy) {
        produceItem = copy->produceItem;
        harvestSound = copy->harvestSound;
        // the image tests the member's address for null before copying the chances, as the sibling does
        if (reinterpret_cast<std::uint32_t*>(&copy->produceChance)) {
            *reinterpret_cast<std::uint32_t*>(produceChance) = *reinterpret_cast<std::uint32_t*>(&copy->produceChance);
        }
    }
}
