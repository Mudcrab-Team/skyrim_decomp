// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLensFlare; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSLensFlareRenderData.h"
#include "TESForm.h"
struct BGSLensFlare {
    TESForm _base;
    BSLensFlareRenderData _base_BSLensFlareRenderData;
};
static_assert(sizeof(BGSLensFlare) == 64, "BGSLensFlare layout differs from the PDB");
