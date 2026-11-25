// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Stand-in declarations: ScriptRunManager, ScriptRunner.
// ScriptRunManager, ScriptRunner, ScriptRunManager::~ScriptRunManager, m_pScriptRunner, pCurrentRunner: SIBLING(fo4-private@1b765c70, author-permission)
// ScriptRunner size (0x60) is the size the sized delete passes in the listing; its members are unknown.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptRunManager.cpp:74
#pragma once

#include <cstdint>

class ScriptRunner
{
public:
    std::uint8_t unk00[0x60];
};

class ScriptRunManager
{
public:
    ~ScriptRunManager();

    ScriptRunner* m_pScriptRunner;  // 00
    ScriptRunner* pCurrentRunner;   // 08
};
