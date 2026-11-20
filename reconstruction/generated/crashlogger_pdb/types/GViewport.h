// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GViewport; size 0x38
#pragma once

#include "Flag_a4a94b8a.h"
struct GViewport {
    int bufferWidth;
    int bufferHeight;
    int left;
    int top;
    int width;
    int height;
    int scissorLeft;
    int scissorTop;
    int scissorWidth;
    int scissorHeight;
    float scale;
    float aspectRatio;
    Flag_a4a94b8a flags;
    unsigned int pad34;
};
static_assert(sizeof(GViewport) == 56, "GViewport layout differs from the PDB");
