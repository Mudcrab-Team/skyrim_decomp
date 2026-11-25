// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x35afc0 Script::SetDestroyedFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:4734
#include "Script_35afc0.h"

bool Script::SetDestroyedFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                  TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                                  float&, unsigned int& auiOffset)
{
    int ivalue = 0;
    bool result = ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &ivalue);
    if (!result)
        return result;
    if (apRefObject)
    {
        if (ivalue)
        {
            apRefObject->SetDestroyed(true);
            return true;
        }
        apRefObject->SetDestroyed(false);
    }
    return true;
}
