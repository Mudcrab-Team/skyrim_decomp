// Source exposure: mixed (pinned image listing and labelled community declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing and labelled declarations. Stamped as a twin of matched 0x3dfeb0 (skyrim_shared/quest/TESQuest): source copied, names replaced by placeholders.
// 0x11dee90 Owner11dee90::QConditions
#include "Owner11dee90.h"

// Not compared: defined so that this unit emits the vftable and with it the deleting destructor.
Owner11dee90::Owner11dee90()
{
}

// guess: same compiled code as matched 0x3dfeb0 apart from relocated fields; its role here is not established.
TESCondition* Owner11dee90::QConditions()
{
    return &objConditions;
}
