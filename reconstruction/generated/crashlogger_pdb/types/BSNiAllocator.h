// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNiAllocator; size 0x8
#pragma once

#include "NiAllocator.h"
struct BSNiAllocator {
    NiAllocator _base;
};
static_assert(sizeof(BSNiAllocator) == 8, "BSNiAllocator layout differs from the PDB");
