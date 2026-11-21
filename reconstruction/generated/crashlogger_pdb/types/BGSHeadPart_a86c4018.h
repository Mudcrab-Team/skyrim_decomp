// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSHeadPart; size 0x120
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSTArray_RE__BGSHeadPart_e1306f84_8a657a0d.h"
#include "HeadPartType.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESModelTextureSwap_014aa4ed.h"
struct BGSColorForm;
struct BGSListForm;
struct BGSTextureSet;
struct BGSHeadPart_a86c4018 {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char pad069;
    unsigned short pad06A;
    HeadPartType type;
    BSTArray_RE__BGSHeadPart_e1306f84_8a657a0d extraParts;
    BGSTextureSet* textureSet;
    unsigned char morphs_raw[120];
    BGSColorForm* color;
    BGSListForm* validRaces;
    BSFixedString_char_83b572b4 formEditorID;
};
static_assert(sizeof(BGSHeadPart_a86c4018) == 288, "BGSHeadPart_a86c4018 layout differs from the PDB");
