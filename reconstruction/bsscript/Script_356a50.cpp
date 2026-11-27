// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x356a50 Script::ResetAIFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:3038
#include "Script_356a50.h"

bool Script::ResetAIFunction(const SCRIPT_PARAMETER*, const char*,
                             TESObjectREFR* apRefObject, TESObjectREFR*, Script*, ScriptLocals*,
                             float&, unsigned int&)
{
    Actor* pActor = dynamic_cast<Actor*>(apRefObject);
    if (pActor)
    {
        unsigned int iFormFlags = pActor->formFlags;
        if ((iFormFlags & 0x800) == 0 && (iFormFlags & 0x20) == 0)
            pActor->EvaluatePackage(false, true);
    }
    return true;
}
