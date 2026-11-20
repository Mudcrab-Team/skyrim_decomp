// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedFile; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "IOTask_02e54452.h"
struct QueuedFile {
    IOTask_02e54452 IOTask;
    int threadDepthMarker;
    unsigned char _pad1C[4];
    QueuedFile* parent;
    char32_t* children;
    int state;
    unsigned char _pad34[4];
};
static_assert(sizeof(QueuedFile) == 56, "QueuedFile layout differs from the PDB");
