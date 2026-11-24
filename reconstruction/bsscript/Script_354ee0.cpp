// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x354ee0 Script::SetCellPublicFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:2488
#include "Script_354ee0.h"

bool Script::SetCellPublicFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                   TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                                   float&, unsigned int& auiOffset)
{
    TESObjectCELL* pCell = 0;
    int iFlag = 0;
    bool result = ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &pCell, &iFlag);
    if (!result)
        return result;
    if (pCell)
        pCell->SetPublic(iFlag > 0);
    return true;
}
