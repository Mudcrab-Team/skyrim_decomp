// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Script, SCRIPT_PARAMETER, ScriptLocals, TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::ParseParameters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG takes a script-data pointer, the target takes the compiled-parameter bytes
// Script::ShowLockpickMenu: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:6733
#pragma once

struct SCRIPT_PARAMETER;
class ScriptLocals;
class TESObjectREFR;

class Script
{
public:
    static bool ParseParameters(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                unsigned int& auiOffset, TESObjectREFR* apRefObject, TESObjectREFR* apContainer,
                                Script* apScript, ScriptLocals* apScriptLocals, ...);
    static bool ShowLockpickMenu(const SCRIPT_PARAMETER*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, float&, unsigned int&);
};
