// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x35fdf0 Script::DamageObjectFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:6356
#include "Script_35fdf0.h"

bool Script::DamageObjectFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                  TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                                  float&, unsigned int& auiOffset)
{
    float fDamage = 0.0f;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &fDamage) || !apRefObject)
        return false;
    TaskQueueInterface::pInstance->QueueScriptFunctionCall(0x116C, apRefObject, fDamage);
    return true;
}
