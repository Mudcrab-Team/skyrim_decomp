// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OBJ_BOOK; size 0x10
#pragma once

#include "Teaches.h"
struct OBJ_BOOK {
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char type;  // Type in the PDB is wider than this slot
    unsigned short pad02;
    unsigned int pad04;
    Teaches teaches;
};
static_assert(sizeof(OBJ_BOOK) == 16, "OBJ_BOOK layout differs from the PDB");
