// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxMovieLoadInfo; size 0x70
#pragma once

#include "GRect_float_808f464e.h"
#include "GString.h"
struct GFxMovieLoadInfo {
    unsigned int totalBytes;
    unsigned int version;
    GRect_float_808f464e frameRect;
    float frameRate;
    unsigned int frameCount;
    unsigned int swfFlags;
    unsigned int unk24;
    unsigned long long unk28;
    unsigned long long unk30;
    unsigned long long unk38;
    unsigned short unk40;
    unsigned short pad42;
    unsigned int unk44;
    GString unk48;
    GString unk50;
    void* unk58;
    unsigned long long unk60;
    unsigned long long unk68;
};
static_assert(sizeof(GFxMovieLoadInfo) == 112, "GFxMovieLoadInfo layout differs from the PDB");
