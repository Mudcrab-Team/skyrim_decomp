// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSArchive; size 0x30
#pragma once

#include "BSArchiveHeader.h"
struct BSDirectoryEntry;
struct BSArchive {
    BSArchiveHeader _base;
    unsigned int pad24;
    BSDirectoryEntry* directories;
};
static_assert(sizeof(BSArchive) == 48, "BSArchive layout differs from the PDB");
