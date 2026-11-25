// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x374880 Script::CompleteAllObjectivesFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:3125
#include "Script_374880.h"

bool Script::CompleteAllObjectivesFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                           TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                                           float&, unsigned int& auiOffset)
{
    TESQuest* pquest = 0;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &pquest))
        return false;
    if (pquest)
        pquest->SetAllObjectivesComplete();
    return true;
}
