// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorBlock.cpp:93
// SaveGame, BlockTimer, BashTimer, CheckDistanceTimer, BGSSaveFormBuffer: SIBLING(fo4-private@1b765c70, author-permission)
// AITimer: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// AITimer::SaveGame: SIBLING(fo4-private@1b765c70, author-permission)
// CombatBehaviorBlock8806a0: GUESS(low)
#pragma once

#include <cstdint>

class BGSSaveFormBuffer;

struct AITimer
{
    float fStartTime;
    float fTargetTime;

    void SaveGame(BGSSaveFormBuffer* a_buffer) const;
};

class CombatBehaviorBlock8806a0
{
public:
    void SaveGame(BGSSaveFormBuffer* a_buffer) const;  // compared: 0x8806a0

    AITimer BlockTimer;
    AITimer BashTimer;
    AITimer CheckDistanceTimer;
};
