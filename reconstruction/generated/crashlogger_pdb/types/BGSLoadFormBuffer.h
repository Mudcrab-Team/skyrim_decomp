// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLoadFormBuffer; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSLoadFormData_51aca0f8.h"
#include "BGSLoadGameBuffer.h"
struct BGSLoadFormBuffer {
    BGSLoadGameBuffer _base;
    BGSLoadFormData_51aca0f8 _base_BGSLoadFormData;
};
static_assert(sizeof(BGSLoadFormBuffer) == 80, "BGSLoadFormBuffer layout differs from the PDB");
