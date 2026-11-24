// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x364860 Script::ToggleWaterCurrentGeometryFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions_Console.cpp:2580
#include "Script_364860.h"

bool Script::ToggleWaterCurrentGeometryFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                                TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                                                float&, unsigned int& auiOffset)
{
    int iShow = 0;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &iShow))
        return false;
    tes->ShowWaterGeometry(iShow != 0);
    return true;
}
