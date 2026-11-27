// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x11b39f0 MoviePlayer::ctor
// Adapted bodies: none
#include "MoviePlayer_11b39f0.h"

// Zero-initialize MoviePlayer handles and flags and create the Bink open semaphore.
MoviePlayer::MoviePlayer() :
    movieLoadingThreadHandle(nullptr),
    sequenceThreadHandle(nullptr),
    currentMovie(nullptr),
    pausedMovie(nullptr),
    threadLoadedMovie(nullptr),
    useThreadLoadedMovie(false),
    unk31(false),
    threadLoadCallback(nullptr),
    waitingForSequenceToEnd(false),
    stopSequence(false),
    letterBoxedSequence(false),
    currentSequenceThreadPriority(0),
    openBinkSemaphore()
{
}
