// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MoviePlayer; size 0x58
#pragma once

#include "BSSemaphore.h"
struct Movie;
struct MoviePlayer_vtbl;
struct MoviePlayer {
    MoviePlayer_vtbl* __vftable;
    void* movieLoadingThreadHandle;
    void* sequenceThreadHandle;
    Movie* currentMovie;
    Movie* pausedMovie;
    Movie* threadLoadedMovie;
    bool useThreadLoadedMovie;
    unsigned char pad31;
    unsigned short pad32;
    unsigned int pad34;
    void* threadLoadCallback;
    bool waitingForSequenceToEnd;
    bool stopSequence;
    bool letterBoxedSequence;
    bool loop;
    int currentSequenceThreadPriority;
    BSSemaphore openBinkSemaphore;
    bool binkOpenSignaled;
    bool streamingInstallComplete;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(MoviePlayer) == 88, "MoviePlayer layout differs from the PDB");
