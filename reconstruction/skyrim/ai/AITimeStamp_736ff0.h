// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// AITimeStamp, AITimeStamp::LoadGame, timeStamp, BGSLoadGameBuffer: CRASHLOGGER_PDB(59818@2026.10.24)
// LoadDataEndian, gCurrentAITime: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_dest, std::uint32_t a_size, std::uint32_t a_count);
};

extern float gCurrentAITime;

struct AITimeStamp
{
    void LoadGame(BGSLoadGameBuffer* a_buf);

    float timeStamp;
};

static_assert(sizeof(AITimeStamp) == 0x04, "AITimeStamp size");
