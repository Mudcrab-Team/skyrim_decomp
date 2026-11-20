// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFile; size 0x180
#pragma once

#include "NiFile.h"
struct BSFile {
    NiFile _base;
    bool useAuxBuffer;
    unsigned char pad049;
    unsigned short pad04A;
    unsigned int pad04C;
    unsigned char* auxBuffer;
    int auxTrueFilePos;
    unsigned int auxBufferMinIndex;
    unsigned int auxBufferMaxIndex;
    unsigned char fileName[260];
    unsigned int result;
    unsigned int ioSize;
    unsigned int trueFilePos;
    unsigned int fileSize;
    bool virtualAlloc;
    unsigned char unk179;
    unsigned short unk17A;
    unsigned char undefined_17c[4];
};
static_assert(sizeof(BSFile) == 384, "BSFile layout differs from the PDB");
