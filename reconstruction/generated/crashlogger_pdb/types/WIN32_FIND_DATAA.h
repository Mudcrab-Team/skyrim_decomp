// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: WIN32_FIND_DATAA; size 0x140
#pragma once

#include "FILETIME_7813ec6f.h"
struct WIN32_FIND_DATAA {
    unsigned int fileAttributes;
    FILETIME_7813ec6f creationTime;
    FILETIME_7813ec6f lastAccessTime;
    FILETIME_7813ec6f lastWriteTime;
    unsigned int fileSizeHi;
    unsigned int fileSizeLo;
    unsigned int reserved0;
    unsigned int reserved1;
    unsigned char fileName[260];
    unsigned char fileNameAlt_raw[16];
};
static_assert(sizeof(WIN32_FIND_DATAA) == 320, "WIN32_FIND_DATAA layout differs from the PDB");
