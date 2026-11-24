// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Stand-in declarations: Script, SCRIPT_PARAMETER, ScriptLocals, TESObjectREFR, MemoryManager, bhkWorld.
// Script, SCRIPT_PARAMETER, ScriptLocals, TESObjectREFR, bhkWorld: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::RunCompaction, MemoryManager, MemoryManager::Instance, MemoryManager::UpdateInitState, MemoryManager::CleanCompactingStore, MemoryManager::CleanPools, bhkWorld::GarbageCollectHavokMemory: SIBLING(fo4-private@1b765c70, author-permission)
// MemoryManager::unk00: GUESS(low); the real size is not needed, only the address of the storage
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions_Console.cpp:2442
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryManager.h:4
#pragma once

struct SCRIPT_PARAMETER;
class ScriptLocals;
class TESObjectREFR;

class bhkWorld
{
public:
    static void GarbageCollectHavokMemory();
};

class MemoryManager
{
public:
    static MemoryManager& Instance();
    static void UpdateInitState(void* apStorage, unsigned int* apFence);
    void CleanCompactingStore(bool abWait);
    void CleanPools();

    unsigned char unk00[1];
};

inline MemoryManager& MemoryManager::Instance()
{
    static char cbuffer[sizeof(MemoryManager)];
    static unsigned int uiinitFence;
    if (uiinitFence != 2)
        UpdateInitState(cbuffer, &uiinitFence);
    return *reinterpret_cast<MemoryManager*>(cbuffer);
}

class Script
{
public:
    static bool RunCompaction(const SCRIPT_PARAMETER*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, float&, unsigned int&);
};
