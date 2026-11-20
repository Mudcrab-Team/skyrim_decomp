// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLoadGameSubBuffer; size 0x8
#pragma once

#include "BGSSaveLoadBuffer.h"
struct BGSLoadGameSubBuffer {
    BGSSaveLoadBuffer buffer;
};
static_assert(sizeof(BGSLoadGameSubBuffer) == 8, "BGSLoadGameSubBuffer layout differs from the PDB");
