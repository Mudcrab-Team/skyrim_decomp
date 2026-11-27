// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// MoviePlayer, Movie, BSSemaphore, movieLoadingThreadHandle, sequenceThreadHandle, currentMovie, pausedMovie, threadLoadedMovie, useThreadLoadedMovie, threadLoadCallback, waitingForSequenceToEnd, stopSequence, letterBoxedSequence, currentSequenceThreadPriority, openBinkSemaphore: CRASHLOGGER_PDB(59818@2026.10.24)
// unk31, unk48, CreateSemaphoreA: GUESS(low)
// 0x11b39f0 MoviePlayer::ctor
// Adapted bodies: none
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(
    void* a_attributes,
    long a_initialCount,
    long a_maximumCount,
    const char* a_name);

struct Movie;

struct BSSemaphore
{
    BSSemaphore() : unk48(CreateSemaphoreA(nullptr, 0, 1, nullptr)) {}

    void* unk48;
};

class MoviePlayer
{
public:
    virtual ~MoviePlayer();
    MoviePlayer();

    void* movieLoadingThreadHandle;
    void* sequenceThreadHandle;
    Movie* currentMovie;
    Movie* pausedMovie;
    Movie* threadLoadedMovie;
    bool useThreadLoadedMovie;
    bool unk31;
    void* threadLoadCallback;
    bool waitingForSequenceToEnd;
    bool stopSequence;
    bool letterBoxedSequence;
    int currentSequenceThreadPriority;
    BSSemaphore openBinkSemaphore;
};

static_assert(offsetof(MoviePlayer, threadLoadCallback) == 0x38, "threadLoadCallback offset");
static_assert(offsetof(MoviePlayer, currentSequenceThreadPriority) == 0x44, "currentSequenceThreadPriority offset");
static_assert(offsetof(MoviePlayer, openBinkSemaphore) == 0x48, "openBinkSemaphore offset");
