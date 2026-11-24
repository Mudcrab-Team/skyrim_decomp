// Source exposure: binary-analysis (the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter, ActorProcess: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); layout reduced to what this function reads
// Function761660, QueryProcess, gProcessQueryEnabled: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ActorProcess;

extern bool gProcessQueryEnabled;
bool QueryProcess(ActorProcess* process);

class PlayerCharacter
{
public:
    bool Function761660();

    char unk000[0xF8];
    ActorProcess* unkF8;
};
