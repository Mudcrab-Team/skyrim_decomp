// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSHeadPart; size 0x120
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BGSHeadPart_e1306f84.h"
#include "HeadPartType.h"
#include "TESForm_4074aa87.h"
#include "TESFullName_88f61e2a.h"
#include "TESModelTextureSwap.h"
struct BGSColorForm_ed89af9a;
struct BGSListForm_bac89fb1;
struct BGSTextureSet_d8b0e61f;
struct BGSHeadPart {
    TESForm_4074aa87 _base;
    TESFullName_88f61e2a _base_TESFullName;
    TESModelTextureSwap _base_TESModelTextureSwap;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char pad069;
    unsigned short pad06A;
    HeadPartType type;
    BSTArray_RE__BGSHeadPart_e1306f84 extraParts;
    BGSTextureSet_d8b0e61f* textureSet;
    unsigned char morphs_raw[120];
    BGSColorForm_ed89af9a* color;
    BGSListForm_bac89fb1* validRaces;
    unsigned char formEditorID_raw[8];
};
static_assert(sizeof(BGSHeadPart) == 288, "BGSHeadPart layout differs from the PDB");
