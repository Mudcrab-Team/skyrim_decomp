// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x364080 Script::SetRumbleFunction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:7954
#include "Script_364080.h"

bool Script::SetRumbleFunction(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                               TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                               float&, unsigned int& auiOffset)
{
    float fLeftMotor = 0.0f;
    float fRightMotor = 0.0f;
    float fDuration = 0.0f;
    if (!ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &fLeftMotor, &fRightMotor, &fDuration))
        return false;
    Rumble::AddDiscreteRumble(Rumble::BIG_MOTOR, fLeftMotor, fDuration);
    Rumble::AddDiscreteRumble(Rumble::SMALL_MOTOR, fRightMotor, fDuration);
    return true;
}
