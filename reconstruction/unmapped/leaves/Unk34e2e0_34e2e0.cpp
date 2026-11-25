// Source exposure: mixed (community headers, the cited sibling and the pinned image listing).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: CC0-1.0
// 0x34e2e0 Unk34e2e0::ShowSubtitle
// Adapted bodies: Unk34e2e0::ShowSubtitle follows momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscriptfunctions.cpp:38914
#include "Unk34e2e0_34e2e0.h"

// Parses one integer argument and stores whether it is non-zero in the subtitle settings.
bool Unk34e2e0::ShowSubtitle(const SCRIPT_PARAMETER* a_paramInfo, const ScriptData* a_scriptData, TESObjectREFR* a_thisObj, TESObjectREFR* a_containingObj, Script* a_scriptObj, ScriptLocals* a_locals, float& a_result, std::uint32_t& a_opcodeOffsetPtr)
{
    std::uint32_t value = 0;
    if (!Script::ParseParameters(a_paramInfo, a_scriptData, a_opcodeOffsetPtr, a_thisObj, a_containingObj, a_scriptObj, a_locals, &value)) {
        return false;
    }
    g_subtitleSettings->showSubtitles = value != 0;
    return true;
}
