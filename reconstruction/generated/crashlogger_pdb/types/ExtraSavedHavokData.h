// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraSavedHavokData; size 0x18
#pragma once

#include "BGSLoadGameSubBuffer.h"
#include "BSExtraData_4ca6af76.h"
struct ExtraSavedHavokData {
    BSExtraData_4ca6af76 _base;
    BGSLoadGameSubBuffer havokBuffer;
};
static_assert(sizeof(ExtraSavedHavokData) == 24, "ExtraSavedHavokData layout differs from the PDB");
