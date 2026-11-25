// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorThread.cpp:281
// CombatBehaviorThread, Load, LoadGame, BGSLoadFormBuffer, LoadVariableSizedValue, iBufferPosition: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// CombatBehaviorThread, Load: CRASHLOGGER_PDB(59818@2026.10.24)
// unk00: GUESS(low)
#pragma once

#include <cstdint>

class BGSLoadFormBuffer
{
public:
    std::uint32_t LoadVariableSizedValue();

    std::uint8_t unk00[0x24];
    std::uint32_t iBufferPosition;  // 24
};

class CombatBehaviorThread
{
public:
    static void Load(BGSLoadFormBuffer* a_buffer, CombatBehaviorThread* a_thread);  // compared: 0x8734d0
    void LoadGame(BGSLoadFormBuffer* a_buffer);
};
