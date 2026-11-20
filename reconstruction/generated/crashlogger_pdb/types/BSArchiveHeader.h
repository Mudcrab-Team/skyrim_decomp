// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSArchiveHeader; size 0x24
#pragma once

#include "ArchiveFlag.h"
struct BSArchiveHeader {
    unsigned int tag;
    unsigned int version;
    unsigned int headerSize;
    ArchiveFlag flags;
    unsigned int directories;
    unsigned int files;
    unsigned int directoryNamesLength;
    unsigned int fileNamesLength;
    unsigned short archiveType;
    unsigned short pad22;
};
static_assert(sizeof(BSArchiveHeader) == 36, "BSArchiveHeader layout differs from the PDB");
