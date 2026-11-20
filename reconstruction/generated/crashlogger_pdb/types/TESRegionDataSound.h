// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionDataSound; size 0x30
#pragma once

#include "BSTArray_RE__TESRegionDataSound__Sound_e64dcd69.h"
#include "TESRegionData.h"
struct BGSMusicType_01bbbee6;
struct TESRegionDataSound {
    TESRegionData _base;
    BGSMusicType_01bbbee6* music;
    BSTArray_RE__TESRegionDataSound__Sound_e64dcd69 sounds;
};
static_assert(sizeof(TESRegionDataSound) == 48, "TESRegionDataSound layout differs from the PDB");
