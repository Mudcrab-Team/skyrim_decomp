// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x3781d0 Script::EnableRumbleFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions_Console.cpp:2475
#include "Script_3781d0.h"

bool Script::EnableRumbleFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                  TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                                  float&, unsigned int& auiOffset)
{
    int iValue = 0;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &iValue))
        return false;
    Rumble::SetRumble(iValue != 0);
    return true;
}
