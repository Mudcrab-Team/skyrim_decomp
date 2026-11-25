// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x356de0 Script::SetAlertFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:3087
#include "Script_356de0.h"

bool Script::SetAlertFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                              TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                              float&, unsigned int& auiOffset)
{
    int iIsAlert = 0;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &iIsAlert))
        return false;
    if (apRefObject)
    {
        Actor* pActor = dynamic_cast<Actor*>(apRefObject);
        if (pActor)
            pActor->SetAlert(iIsAlert > 0);
    }
    return true;
}
