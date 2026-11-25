// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Script/BGSGameScriptUtils.cpp:97
// 0x9cf9b0 GameScript::WriteFormIDToSave
// Adapted bodies: GameScript::WriteFormIDToSave from the sibling source named above
#include "BGSNumericIDIndex_9cf9b0.h"

bool GameScript::WriteFormIDToSave(BSStorage& a_storage, std::uint32_t a_formID)
{
    BGSNumericIDIndex formIDIndex;
    formIDIndex.SetNumericID(a_formID);
    return a_storage.Write(3, reinterpret_cast<const std::uint8_t*>(&formIDIndex)) == 0;
}
