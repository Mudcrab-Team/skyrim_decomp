// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x351170 Script::SetScaleFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:1380
#include "Script_351170.h"

bool Script::SetScaleFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                              TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                              float&, unsigned int& auiOffset)
{
    float fScale = 0.0f;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &fScale))
        return false;
    TaskQueueInterface::pInstance->QueueScriptFunctionCall(0x113C, apRefObject, fScale);
    return true;
}
