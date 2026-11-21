// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLoadFormBuffer; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSLoadFormData.h"
#include "BGSLoadGameBuffer.h"
struct BGSLoadFormBuffer_4e5a6128 {
    BGSLoadGameBuffer _base;
    BGSLoadFormData _base_BGSLoadFormData;
};
static_assert(sizeof(BGSLoadFormBuffer_4e5a6128) == 80, "BGSLoadFormBuffer_4e5a6128 layout differs from the PDB");
