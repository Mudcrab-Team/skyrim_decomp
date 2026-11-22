// Source exposure: mixed (pinned image listing and labelled declarations).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing with labelled declarations.
// Adapted bodies: none.
// ClearProfilerTimersFunctor, Script::profilerTimer: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x344760 Script::InitItemImpl
// 0x3463a0 Script::GetProcessScripts
// 0x3466f0 ClearProfilerTimersFunctor
#include "Script.h"

// g_scriptProcessScripts: GUESS(low); a mutable global the compared GetProcessScripts reads at 0x207e511
extern bool g_scriptProcessScripts;
// ScriptInitItemHelper: GUESS(low); the target tail-jumps to it with this passed twice, at 0x344770
void ScriptInitItemHelper(Script* a_self, Script* a_other);

void Script::InitItemImpl()
{
    ScriptInitItemHelper(this, this);
}

bool Script::GetProcessScripts()
{
    return g_scriptProcessScripts;
}
// Reset this script's accumulated profiling time and continue enumeration.
std::uint32_t ClearProfilerTimersFunctor(Script& a_script)
{
    a_script.profilerTimer = 0.0f;
    return 1;
}
