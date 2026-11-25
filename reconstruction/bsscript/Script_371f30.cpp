// Source exposure: mixed (community headers, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x371f30 Script::RunCompaction
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/TESScriptFunctions_Console.cpp:2442
#include "Script_371f30.h"

bool Script::RunCompaction(const SCRIPT_PARAMETER*, const char*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*, float&, unsigned int&)
{
    bhkWorld::GarbageCollectHavokMemory();
    MemoryManager::Instance().CleanCompactingStore(false);
    MemoryManager::Instance().CleanPools();
    return true;
}
