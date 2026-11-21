// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ID; size 0xc
#pragma once

#include "FileID.h"
struct ID {
    FileID _base;
    unsigned int dir;
};
static_assert(sizeof(ID) == 12, "ID layout differs from the PDB");
