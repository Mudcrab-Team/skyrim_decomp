// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLocation; size 0xf0
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSKeywordForm.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTArray_RE__BGSLocation__KEYWORD_DATA_da880791.h"
#include "BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937.h"
#include "BSTArray_RE__SpecialRefData_62f3bc89_c51a08b6.h"
#include "BSTArray_RE__UniqueNPCData_c87db6c7_f11f61f4.h"
#include "NiPointer_RE__QueuedPromoteLocationReferencesTask_280611f1.h"
#include "TESForm_4074aa87.h"
#include "TESFullName_88f61e2a.h"
struct BGSMusicType;
struct OverrideData;
struct TESFaction;
struct BGSLocation_075ae773 {
    TESForm_4074aa87 _base;
    TESFullName_88f61e2a _base_TESFullName;
    BGSKeywordForm _base_BGSKeywordForm;
    BGSLocation_075ae773* parentLoc;
    TESFaction* unreportedCrimeFaction;
    BGSMusicType* musicType;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 worldLocMarker;
    float worldLocRadius;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 horseLocMarker;
    unsigned int pad6C;
    BSTArray_RE__SpecialRefData_62f3bc89_c51a08b6 specialRefs;
    BSTArray_RE__UniqueNPCData_c87db6c7_f11f61f4 uniqueNPCs;
    OverrideData* overrideData;
    NiPointer_RE__QueuedPromoteLocationReferencesTask_280611f1 promoteRefsTask;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937 promotedRefs;
    int loadedCount;
    unsigned int fileOffset;
    BSTArray_RE__BGSLocation__KEYWORD_DATA_da880791 keywordData;
    unsigned int lastChecked;
    bool cleared;
    bool everCleared;
    unsigned short padEE;
};
static_assert(sizeof(BGSLocation_075ae773) == 240, "BGSLocation_075ae773 layout differs from the PDB");
