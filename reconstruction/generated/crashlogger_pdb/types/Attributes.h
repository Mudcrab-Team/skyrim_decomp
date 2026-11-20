// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Attributes; size 0x10
#pragma once

#include "Error.h"
struct Attributes {
    Error lastError;
    unsigned int pad24;
    void* handle;
};
static_assert(sizeof(Attributes) == 16, "Attributes layout differs from the PDB");
