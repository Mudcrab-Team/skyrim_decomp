// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpace__BaseData; size 0x50
#pragma once

#include "TESImageSpace__CinematicData.h"
#include "TESImageSpace__DOFData.h"
#include "TESImageSpace__HDRData.h"
#include "TESImageSpace__TintData.h"
struct TESImageSpace__BaseData {
    TESImageSpace__HDRData Hdr_0;
    TESImageSpace__CinematicData Cinematic_24;
    TESImageSpace__TintData Tint_30;
    TESImageSpace__DOFData DepthOfField_40;
};
static_assert(sizeof(TESImageSpace__BaseData) == 80, "TESImageSpace__BaseData layout differs from the PDB");
