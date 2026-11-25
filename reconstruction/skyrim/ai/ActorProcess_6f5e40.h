// Source exposure: binary-analysis (the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess, HighProcessData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); layout reduced to the members this function uses
// unk2A4: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function6f5e40, unk10, unk2AC: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct HighProcessData
{
    char unk000[0x2A4];
    float unk2A4;
    char unk2A8[4];
    float unk2AC;
};

class ActorProcess
{
public:
    void Function6f5e40(float value);

    char unk000[0x10];
    HighProcessData* unk10;
};
