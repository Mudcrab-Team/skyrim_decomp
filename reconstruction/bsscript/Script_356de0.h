// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Script, SCRIPT_PARAMETER, ScriptLocals: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::ParseParameters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG takes a script-data pointer, the target takes the compiled-parameter bytes
// Script::SetAlertFunction: SIBLING(fo4-private@1b765c70, author-permission)
// TESForm, TESObjectREFR, sourceFiles, formFlags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::SetAlert: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:3087
#pragma once

struct SCRIPT_PARAMETER;
class ScriptLocals;
class Actor;

class TESForm
{
public:
    virtual ~TESForm();

    void* sourceFiles;  // 08
    unsigned int formFlags;  // 10
};

class TESObjectREFR : public TESForm
{
};

class Actor : public TESObjectREFR
{
public:
    void SetAlert(bool abAlert);
};

class Script
{
public:
    static bool ParseParameters(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                unsigned int& auiOffset, TESObjectREFR* apRefObject, TESObjectREFR* apContainer,
                                Script* apScript, ScriptLocals* apScriptLocals, ...);
    static bool SetAlertFunction(const SCRIPT_PARAMETER*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, float&, unsigned int&);
};
