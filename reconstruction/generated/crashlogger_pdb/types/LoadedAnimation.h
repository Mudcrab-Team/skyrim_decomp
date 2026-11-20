// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadedAnimation; size 0x18
#pragma once

#include "AnimationFileInfo.h"
struct LoadedAnimation {
    void* unk00;
    AnimationFileInfo fileInfo;
    unsigned short counter;
    unsigned char undefined_16[2];
};
static_assert(sizeof(LoadedAnimation) == 24, "LoadedAnimation layout differs from the PDB");
