// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x39afb0 BGSQuestObjective::InitializeData
// Adapted bodies: BGSQuestObjective::InitializeData follows fo4-private@1b765c70 src/Shared/TESForms/Character/BGSQuestObjective.cpp:59
#include "BGSQuestObjective_39afb0.h"

void BGSQuestObjective::InitializeData()
{
    usIndex = 0;
    strDisplayText.SetString("");
    bInitialized = false;
    cState = 0;
    pOwnerQuest = 0;
    uiFlags = 0;
    uiNumTargets = 0;
    pTargetsA = 0;
}
