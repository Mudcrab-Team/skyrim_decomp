// Source exposure: binary-analysis (the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, HighProcessData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); layout reduced to the members this function uses
// Function6ffeb0, unk10, word3F8, word3FA: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct HighProcessData
{
    char unk000[0x3F8];
    std::int16_t word3F8;
    std::int16_t word3FA;
};

class ActorProcess
{
public:
    void Function6ffeb0(std::uint32_t slot, std::uint16_t value);

    char unk000[0x10];
    HighProcessData* unk10;
};
