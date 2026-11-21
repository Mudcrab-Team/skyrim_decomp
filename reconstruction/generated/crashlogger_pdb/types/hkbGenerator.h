// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbGenerator; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkbNode.h"
struct hkbGenerator {
    hkbNode _base;
};
static_assert(sizeof(hkbGenerator) == 72, "hkbGenerator layout differs from the PDB");
