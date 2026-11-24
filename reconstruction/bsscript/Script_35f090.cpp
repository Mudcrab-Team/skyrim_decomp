// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x35f090 Script::EssentailDeathReloadFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:245
#include "Script_35f090.h"

bool Script::EssentailDeathReloadFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                          TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                                          float&, unsigned int& auiOffset)
{
    char pMessage[512];
    bool result = ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, pMessage);
    if (!result)
        return result;
    return true;
}
