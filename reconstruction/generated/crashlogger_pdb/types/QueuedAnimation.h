// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedAnimation; size 0x10
#pragma once

#include "AnimationFileInfo.h"
struct QueuedAnimation {
    unsigned int unk00;
    AnimationFileInfo fileInfo;
};
static_assert(sizeof(QueuedAnimation) == 16, "QueuedAnimation layout differs from the PDB");
