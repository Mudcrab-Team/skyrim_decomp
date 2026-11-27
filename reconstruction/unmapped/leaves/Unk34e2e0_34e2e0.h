// Source exposure: mixed (community headers, the cited sibling and the pinned image listing).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: Unk34e2e0::ShowSubtitle follows momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp:38914
// Script::ParseParameters, SCRIPT_PARAMETER, SCRIPT_FUNCTION::ScriptData, TESObjectREFR, Script, ScriptLocals: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the declarations the call needs, ParseParameters is a static variadic function there
// Unk34e2e0: GUESS(low); placeholder owner of this unit, the handler is the console command ShowSubtitle (name from the inventory)
// Unk34e2e0::ShowSubtitle, SubtitleSettings, g_subtitleSettings, showSubtitles, unk00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct SCRIPT_PARAMETER;
struct ScriptData;
class TESObjectREFR;
class ScriptLocals;

class Script
{
public:
    static bool ParseParameters(const SCRIPT_PARAMETER* a_paramInfo, const ScriptData* a_scriptData, std::uint32_t& a_opcodeOffsetPtr, TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, ...);
};

class SubtitleSettings
{
public:
    std::uint8_t unk00[0xD];
    bool showSubtitles;  // 0D
};

extern SubtitleSettings* g_subtitleSettings;

class Unk34e2e0
{
public:
    static bool ShowSubtitle(const SCRIPT_PARAMETER* a_paramInfo, const ScriptData* a_scriptData, TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, float& a_result, std::uint32_t& a_opcodeOffsetPtr);
};
