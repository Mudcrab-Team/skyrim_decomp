// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESActionData; size 0x60
#pragma once

#include "BGSActionData.h"
struct TESActionData {
    BGSActionData _base;
};
static_assert(sizeof(TESActionData) == 96, "TESActionData layout differs from the PDB");
