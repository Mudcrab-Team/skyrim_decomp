// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Script/BGSGameScriptUtils.cpp:120
// 0x9cfa00 GameScript::ReadFormIDFromSaveNoRemap
// Adapted bodies: GameScript::ReadFormIDFromSaveNoRemap from the sibling source named above
#include "BGSNumericIDIndex_9cfa00.h"

bool GameScript::ReadFormIDFromSaveNoRemap(const BSStorage& a_storage, std::uint32_t& a_formID)
{
    BGSNumericIDIndex formIDIndex;
    bool success = !a_storage.Read(3, formIDIndex.cData1);
    if (success)
        a_formID = formIDIndex.GetNumericID();
    return success;
}
