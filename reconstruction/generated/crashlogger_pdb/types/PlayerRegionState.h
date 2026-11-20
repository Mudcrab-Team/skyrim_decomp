// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerRegionState; size 0x60
#pragma once

#include "BSTArray_RE__TESRegionDataSound_2a47de28.h"
#include "BSTArray_RE__TESRegion_27348eeb.h"
#include "BSTEventSink_RE__BGSActorCellEvent_66105fe9.h"
#include "BSTSingletonSDM_RE__PlayerRegionState_dff14dd9.h"
struct BGSMusicType_01bbbee6;
struct BSTEventSource_RE__BGSActorCellEvent_266e4475;
struct TESRegion;
struct PlayerRegionState {
    BSTEventSink_RE__BGSActorCellEvent_66105fe9 _base;
    BSTSingletonSDM_RE__PlayerRegionState_dff14dd9 _base_BSTSingletonSDM_RE_PlayerRegionState_;
    unsigned char undefined_9[7];
    BSTArray_RE__TESRegionDataSound_2a47de28 soundData;
    BSTArray_RE__TESRegion_27348eeb regions;
    bool inSoundRegion;
    bool unk41;
    unsigned short pad42;
    unsigned int pad44;
    TESRegion* currentRegion;
    BGSMusicType_01bbbee6* currentMusicType;
    BSTEventSource_RE__BGSActorCellEvent_266e4475* actorCellEventSource;
};
static_assert(sizeof(PlayerRegionState) == 96, "PlayerRegionState layout differs from the PDB");
