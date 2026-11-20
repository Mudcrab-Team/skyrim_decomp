// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDualCastData; size 0x60
#pragma once

#include "BGSDualCastDataDEF.h"
#include "TESBoundObject_fc790793.h"
struct BGSDualCastData {
    TESBoundObject_fc790793 _base;
    BGSDualCastDataDEF data;
};
static_assert(sizeof(BGSDualCastData) == 96, "BGSDualCastData layout differs from the PDB");
