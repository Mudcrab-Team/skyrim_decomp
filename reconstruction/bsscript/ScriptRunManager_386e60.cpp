// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x386e60 ScriptRunManager::~ScriptRunManager
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptRunManager.cpp:74
#include "ScriptRunManager_386e60.h"

ScriptRunManager::~ScriptRunManager()
{
    if (m_pScriptRunner)
    {
        delete m_pScriptRunner;
        m_pScriptRunner = 0;
    }
    pCurrentRunner = 0;
}
