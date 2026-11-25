// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x3e1c70 TESQuestStageItem::SetConditions
// Adapted bodies: TESQuestStageItem::SetConditions follows fo4-private@1b765c70 src/Shared/TESForms/Character/TESQuestStage.cpp:214
#include "TESQuestStageItem_3e1c70.h"

void TESQuestStageItem::SetConditions(TESCondition* apCond)
{
    if (apCond)
        objConditions.Copy(apCond, nullptr);
    else {
        TESCondition temp;
        objConditions.Copy(&temp, nullptr);
    }
}
