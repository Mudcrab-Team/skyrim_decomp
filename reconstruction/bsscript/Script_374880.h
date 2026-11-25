// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Script, SCRIPT_PARAMETER, ScriptLocals, TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::ParseParameters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG takes a script-data pointer, the target takes the compiled-parameter bytes
// Script::CompleteAllObjectivesFunction: SIBLING(fo4-private@1b765c70, author-permission)
// TESQuest: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESQuest::SetAllObjectivesComplete: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:3125
#pragma once

struct SCRIPT_PARAMETER;
class ScriptLocals;
class TESObjectREFR;
class TESQuest;

class TESQuest
{
public:
    void SetAllObjectivesComplete();
};

class Script
{
public:
    static bool ParseParameters(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                unsigned int& auiOffset, TESObjectREFR* apRefObject, TESObjectREFR* apContainer,
                                Script* apScript, ScriptLocals* apScriptLocals, ...);
    static bool CompleteAllObjectivesFunction(const SCRIPT_PARAMETER*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, float&, unsigned int&);
};
