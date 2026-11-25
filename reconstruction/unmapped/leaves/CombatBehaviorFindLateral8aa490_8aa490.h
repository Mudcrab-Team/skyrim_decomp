// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorFindAttackLocation.cpp:126
// CombatObject, Save, spPath, spAimController, CheckLOSTimer, SaveGame, BGSSaveFormBuffer: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// AITimer: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// AITimer::SaveGame: SIBLING(fo4-private@1b765c70, author-permission)
// CombatBehaviorFindLateral8aa490: GUESS(low)
#pragma once

#include <cstdint>

class BGSSaveFormBuffer;

class CombatObject
{
public:
    static void Save(BGSSaveFormBuffer* a_buffer, CombatObject* a_object);
};

struct AITimer
{
    float fStartTime;
    float fTargetTime;

    void SaveGame(BGSSaveFormBuffer* a_buffer) const;
};

class CombatBehaviorFindLateral8aa490
{
public:
    void SaveGame(BGSSaveFormBuffer* a_buffer) const;  // compared: 0x8aa490

    CombatObject* spPath;
    CombatObject* spAimController;
    AITimer CheckLOSTimer;
};
