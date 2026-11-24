// Source exposure: mixed (community headers, CrashLogger layouts, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Stand-in declarations: ScriptLocals, Script, ScriptLocalList.
// ScriptLocals, Script: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ScriptLocals::InitializeData, ScriptLocals::masterScript, ScriptLocals::actionList, ScriptLocals::localList: CRASHLOGGER_PDB(59818@2026.10.24)
// ScriptLocals::ClearActionList, ScriptLocals::ClearVariableList, Script::CreateLocalList: SIBLING(fo4-private@1b765c70, author-permission)
// ScriptLocalList: GUESS(low); the list type behind localList, only its pointer is used
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScript.cpp:230
#pragma once

#include <cstdint>

struct ScriptLocalList;

class Script
{
public:
    ScriptLocalList* CreateLocalList();
};

class ScriptLocals
{
public:
    void InitializeData(Script* apScript);
    void ClearActionList();
    void ClearVariableList();

    Script* masterScript;     // 00
    std::uint8_t unk08[8];    // 08
    void* actionList;         // 10
    ScriptLocalList* localList;  // 18
};
