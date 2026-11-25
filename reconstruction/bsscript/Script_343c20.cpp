// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x343c20 Script::RunScriptEffectFinish
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScript.cpp:687
#include "Script_343c20.h"

void Script::RunScriptEffectFinish(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals)
{
    ScriptRunManager::Instance()->Run(this, apTargetRef, apEffectLocals, nullptr, false, false, true, 0.0f);
}
