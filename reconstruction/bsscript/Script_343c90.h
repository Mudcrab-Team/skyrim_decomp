// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Stand-in declarations: Script, ScriptLocals, TESObjectREFR, ScriptRunManager.
// Script, ScriptLocals, TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::RunScriptEffectUpdate, ScriptRunManager, ScriptRunManager::Instance, ScriptRunManager::Run: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScript.cpp:693
#pragma once

class ScriptLocals;
class TESObjectREFR;

class Script
{
public:
    void RunScriptEffectUpdate(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals, float afSecondsElapsed);
};

class ScriptRunManager
{
public:
    static ScriptRunManager* Instance();
    bool Run(Script* apScript, TESObjectREFR* apOwnerObject, ScriptLocals* apOwnerVars,
             TESObjectREFR* apOwnerContainer, bool abIsPartialScript, bool abScriptEffectStart,
             bool abScriptEffectFinish, float afSecondsElapsed);
};
