// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSIdleMarker; size 0x78
#pragma once

#include "BGSIdleCollection_ffcdd2aa.h"
#include "TESBoundObject_fc790793.h"
#include "TESModel_c52655e4.h"
struct BGSIdleMarker {
    TESBoundObject_fc790793 _base;
    TESModel_c52655e4 _base_TESModel;
    BGSIdleCollection_ffcdd2aa _base_BGSIdleCollection;
};
static_assert(sizeof(BGSIdleMarker) == 120, "BGSIdleMarker layout differs from the PDB");
