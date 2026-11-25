// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x364d20 Script::PreloadMagicEffect
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:5836
#include "Script_364d20.h"

bool Script::PreloadMagicEffect(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                                float&, unsigned int& auiOffset)
{
    EffectSetting* peffectSetting = 0;
    bool result = ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &peffectSetting);
    if (!result)
        return result;
    return true;
}
