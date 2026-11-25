// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x360f40 Script::ShowLockpickMenu
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:6733
#include "Script_360f40.h"

bool Script::ShowLockpickMenu(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                              TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript, ScriptLocals* apScriptLocals,
                              float&, unsigned int& auiOffset)
{
    int ilockDifficulty = 3;
    ParseParameters(apParameters, apCompiledParams, auiOffset, apRefObject, apContainer, apScript, apScriptLocals, &ilockDifficulty);
    return true;
}
