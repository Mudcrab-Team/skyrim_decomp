// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFile; size 0x48
#pragma once

#include "NiBinaryStream.h"
#include "OpenMode.h"
struct iobuf;
struct NiFile {
    NiBinaryStream _base;
    unsigned int bufferAllocSize;
    unsigned int bufferReadSize;
    unsigned int pos;
    unsigned int total;
    unsigned char* buffer;
    iobuf* file;
    OpenMode mode;
    bool isGood;
    unsigned char pad45;
    unsigned short pad46;
};
static_assert(sizeof(NiFile) == 72, "NiFile layout differs from the PDB");
