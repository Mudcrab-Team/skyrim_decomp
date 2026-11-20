// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMusicType; size 0x78
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "BSTArray_BSIMusicTrack_b518d627.h"
#include "BSTArray_uint32.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSMusicType__VFTable;
struct BSIMusicType__VFTable;
struct BGSMusicType {
    BGSMusicType__VFTable* vftable_BGSMusicType_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    BSIMusicType__VFTable* vftable_BSIMusicType_20;
    unsigned int MusicTypeFlags_28;
    char Priority_2C;
    char Padding_2D;
    unsigned short DucksOtherMusicBy_2E;
    float FadeTime_30;
    int CurrentTrackIndex_34;
    BSTArray_uint32 TrackHistory_38;
    BSTArray_BSIMusicTrack_b518d627 Tracks_50;
    char _pad_68[8];
    BSFixedString FormEditorID_70;
};
static_assert(sizeof(BGSMusicType) == 120, "BGSMusicType layout differs from the PDB");
