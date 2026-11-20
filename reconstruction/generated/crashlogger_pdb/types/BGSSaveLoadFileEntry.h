// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveLoadFileEntry; size 0x78
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "FILETIME_7813ec6f.h"
#include "SaveType.h"
struct BGSSaveLoadFileEntry {
    BSFixedString_char_83b572b4 fileName;
    BSFixedString_char_83b572b4 characterName;
    BSFixedString_char_83b572b4 characterTitle;
    BSFixedString_char_83b572b4 currentLocation;
    BSFixedString_char_83b572b4 playTime;
    BSFixedString_char_83b572b4 characterRace;
    int saveVersion;
    unsigned int saveNumber;
    unsigned int characterLevel;
    float currentExperience;
    float requiredExperience;
    unsigned int screenshotWidth;
    unsigned int screenshotHeight;
    unsigned int unk4C;
    FILETIME_7813ec6f fileTime;
    FILETIME_7813ec6f saveTime;
    int unk60;
    bool loaded;
    bool unk65;
    bool unk66;
    unsigned char unk67;
    unsigned char unk68;
    bool modded;
    unsigned short pad6A;
    unsigned int characterID;
    SaveType saveType;
    unsigned int pad74;
};
static_assert(sizeof(BGSSaveLoadFileEntry) == 120, "BGSSaveLoadFileEntry layout differs from the PDB");
