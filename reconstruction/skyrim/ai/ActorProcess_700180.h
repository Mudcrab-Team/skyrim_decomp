// Source exposure: binary-analysis (the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, HighProcessData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); layout reduced to the members this function uses
// Function700180, unk10, word1C, word20, word24: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct HighProcessData
{
    char unk00[0x1C];
    float word1C;
    float word20;
    float word24;
};

class ActorProcess
{
public:
    void Function700180(std::int32_t which, float value);

    char unk000[0x10];
    HighProcessData* unk10;
};
