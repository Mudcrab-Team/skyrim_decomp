// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraSavedAnimation; size 0x18
#pragma once

#include "BGSLoadGameSubBuffer.h"
#include "BSExtraData_4ca6af76.h"
struct ExtraSavedAnimation {
    BSExtraData_4ca6af76 _base;
    BGSLoadGameSubBuffer animationBuffer;
};
static_assert(sizeof(ExtraSavedAnimation) == 24, "ExtraSavedAnimation layout differs from the PDB");
