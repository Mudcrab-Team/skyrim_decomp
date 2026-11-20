// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSAudioManagerThread; size 0x68
#pragma once

#include "BSThread.h"
struct BSAudioManagerThread {
    BSThread _base;
    void* semaphore1;
    void* semaphore2;
    bool unk60;
    bool unk61;
    unsigned char pad62[2];
    unsigned int sleepTime;
};
static_assert(sizeof(BSAudioManagerThread) == 104, "BSAudioManagerThread layout differs from the PDB");
