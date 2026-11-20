// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLocation; size 0xf0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSKeywordForm_9c083c55.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTArray_RE__BGSLocation__KEYWORD_DATA_da880791_9b19a5e7.h"
#include "BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8.h"
#include "BSTArray_RE__SpecialRefData_62f3bc89.h"
#include "BSTArray_RE__UniqueNPCData_c87db6c7.h"
#include "NiPointer_RE__QueuedPromoteLocationReferencesTask_280611f1.h"
#include "TESForm.h"
#include "TESFullName.h"
struct BGSMusicType_01bbbee6;
struct OverrideData_cfdb4135;
struct TESFaction_fe5903c5;
struct BGSLocation {
    TESForm _base;
    TESFullName _base_TESFullName;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    BGSLocation* parentLoc;
    TESFaction_fe5903c5* unreportedCrimeFaction;
    BGSMusicType_01bbbee6* musicType;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 worldLocMarker;
    float worldLocRadius;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 horseLocMarker;
    unsigned int pad6C;
    BSTArray_RE__SpecialRefData_62f3bc89 specialRefs;
    BSTArray_RE__UniqueNPCData_c87db6c7 uniqueNPCs;
    OverrideData_cfdb4135* overrideData;
    NiPointer_RE__QueuedPromoteLocationReferencesTask_280611f1 promoteRefsTask;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8 promotedRefs;
    int loadedCount;
    unsigned int fileOffset;
    BSTArray_RE__BGSLocation__KEYWORD_DATA_da880791_9b19a5e7 keywordData;
    unsigned int lastChecked;
    bool cleared;
    bool everCleared;
    unsigned short padEE;
};
static_assert(sizeof(BGSLocation) == 240, "BGSLocation layout differs from the PDB");
