// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// MoviePlayer, WaitForSequenceToBegin, Movie, sequenceThreadHandle, currentMovie: CRASHLOGGER_PDB(59818@2026.10.24)
// unk00, unk28, Sleep: GUESS(low)
// 0x11b42a0 MoviePlayer::WaitForSequenceToBegin
// Adapted bodies: none
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) void __stdcall Sleep(std::uint32_t a_milliseconds);

struct Movie
{
    std::uint8_t unk00[0x28];
    bool unk28;
};

class MoviePlayer
{
public:
    void WaitForSequenceToBegin();

    std::uint8_t unk00[0x10];
    void* sequenceThreadHandle;
    Movie* currentMovie;
};

static_assert(offsetof(MoviePlayer, sequenceThreadHandle) == 0x10, "sequenceThreadHandle offset");
static_assert(offsetof(MoviePlayer, currentMovie) == 0x18, "currentMovie offset");
static_assert(offsetof(Movie, unk28) == 0x28, "unk28 offset");
