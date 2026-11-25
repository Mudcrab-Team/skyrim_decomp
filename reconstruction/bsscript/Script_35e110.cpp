// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x35e110 Script::ResetCellFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:5902
#include "Script_35e110.h"

bool Script::ResetCellFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                               TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                               float&, unsigned int& auiOffset)
{
    TESObjectCELL* pcell = 0;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &pcell))
        return false;
    if (pcell)
        pcell->SetDetachTime(0xFFFFFFFF, false);
    return true;
}
