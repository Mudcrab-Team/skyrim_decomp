// Source exposure: mixed (community headers, CrashLogger names, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x35e4a0 Script::ForceWeather
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:486
#include "Script_35e4a0.h"

bool Script::ForceWeather(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                          TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript,
                          ScriptLocals* apScriptLocals, float& afReturnValue, unsigned int& auiOffset)
{
    TESWeather* pnewWeather = 0;
    int ioverride = 0;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer,
                         apScript, apScriptLocals, &pnewWeather, &ioverride))
        return false;
    TaskQueueInterface::pInstance->QueueForceWeather(pnewWeather, ioverride != 0);
    return true;
}
