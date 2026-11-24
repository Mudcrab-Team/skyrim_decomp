// Source exposure: mixed (community headers, CrashLogger names, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Stand-in declarations: Script, ScriptLocals, SCRIPT_PARAMETER, TESObjectREFR, TESWeather, TaskQueueInterface.
// Script, SCRIPT_PARAMETER, ScriptLocals, TESObjectREFR, TESWeather, TaskQueueInterface: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::ParseParameters, TaskQueueInterface::QueueForceWeather: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; ParseParameters takes the compiled-parameter bytes here, NG takes a script-data pointer
// Script::ForceWeather: SIBLING(fo4-private@1b765c70, author-permission) CRASHLOGGER_PDB(59818@2026.10.24)
// TaskQueueInterface::pInstance: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions.cpp:486
#pragma once

struct SCRIPT_PARAMETER;
class ScriptLocals;
class TESObjectREFR;
class TESWeather;

class Script
{
public:
    static bool ParseParameters(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                                unsigned int& auiOffset, TESObjectREFR* apRefObject,
                                TESObjectREFR* apContainer, Script* apScript,
                                ScriptLocals* apScriptLocals, ...);
    static bool ForceWeather(const SCRIPT_PARAMETER* apParameters, const char* apCompiledParams,
                             TESObjectREFR* apRefObject, TESObjectREFR* apContainer, Script* apScript,
                             ScriptLocals* apScriptLocals, float& afReturnValue, unsigned int& auiOffset);
};

class TaskQueueInterface
{
public:
    void QueueForceWeather(TESWeather* apWeather, bool abOverride);

    static TaskQueueInterface* pInstance;
};
