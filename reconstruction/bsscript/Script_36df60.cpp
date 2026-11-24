// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x36df60 Script::RumbleManager
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions_Console.cpp:37
#include "Script_36df60.h"

bool Script::RumbleManager(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                           TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                           float&, unsigned int& auiOffset)
{
    float leftStrength = 0.0f;
    float leftTime = 0.0f;
    float rightStrength = 0.0f;
    float rightTime = 0.0f;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &leftStrength, &leftTime, &rightStrength, &rightTime))
        return false;
    Rumble::AddDiscreteRumble(Rumble::SMALL_MOTOR, leftStrength, leftTime);
    Rumble::AddDiscreteRumble(Rumble::BIG_MOTOR, rightStrength, rightTime);
    return true;
}
