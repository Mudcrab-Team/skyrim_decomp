// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveLoadManager; size 0x418
#pragma once

#include "BGSSaveLoadManager__Thread.h"
#include "BSFixedString_char_83b572b4.h"
#include "BSTArray_RE__BGSSaveLoadFileEntry_de5d1f14.h"
#include "BSTArray_RE__BGSSaveLoadManager__SaveEntry_424aa5fb.h"
#include "BSTArray_RE__detail__BSFixedString_char_dee190e5.h"
#include "BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3.h"
#include "BSTEventSink_RE__BSSaveDataEvent_771b90b5.h"
#include "BSTEventSink_RE__BSSystemEvent_a1441324.h"
#include "BSTEventSink_RE__RaceSexMenuEvent__NameChangedEvent_5a180ea4.h"
#include "BSTEventSource_RE__BGSSaveLoadManagerEvent_d762136b.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_f36d4f05.h"
struct BGSSaveLoadFileEntry;
struct BGSSaveLoadManager {
    BSTEventSink_RE__BSSaveDataEvent_771b90b5 _base;
    BSTEventSink_RE__RaceSexMenuEvent__NameChangedEvent_5a180ea4 _base_BSTEventSink_RE_RaceSexMenuEvent_NameChangedEvent_;
    BSTEventSink_RE__BSSystemEvent_a1441324 _base_BSTEventSink_RE_BSSystemEvent_;
    BSTEventSource_RE__BGSSaveLoadManagerEvent_d762136b _base_BSTEventSource_RE_BGSSaveLoadManagerEvent_;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_f36d4f05 characterIDNameMap;
    unsigned long long unk0A0;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned long long unk0B8;
    unsigned long long unk0C0;
    unsigned long long unk0C8;
    unsigned int currentCharacterID;
    unsigned int currentCharacterModded;
    unsigned int displayCharacterID;
    unsigned int displayCharacterModded;
    unsigned int unk0E0;
    unsigned int unk0E4;
    BSTArray_RE__BGSSaveLoadManager__SaveEntry_424aa5fb loadedEntries;
    BSTArray_RE__BGSSaveLoadFileEntry_de5d1f14 saveGameList;
    unsigned char unk118;
    unsigned char pad119;
    unsigned short pad11A;
    unsigned int saveCount;
    unsigned char unk120;
    unsigned char pad121;
    unsigned short pad122;
    unsigned int pad124;
    unsigned long long tickCount;
    unsigned char unk130;
    unsigned char pad131;
    unsigned short pad132;
    unsigned int pad134;
    unsigned char lastFileFullName[260];
    unsigned int pad23C;
    BSFixedString_char_83b572b4 lastFileName;
    unsigned short lastFileNameLength;
    unsigned short maxFileNameLength;
    unsigned int unk24C;
    int unk250;
    unsigned int pad254;
    unsigned long long unk258;
    unsigned short unk260;
    unsigned short unk262;
    unsigned int unk264;
    unsigned long long unk268;
    unsigned int unk270;
    unsigned int unk274;
    unsigned long long unk278;
    unsigned long long unk280;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned long long unk290;
    unsigned long long unk298;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned long long unk2A8;
    unsigned short unk2B0;
    unsigned short unk2B2;
    unsigned char undefined_2b4[4];
    BGSSaveLoadFileEntry* pendingSaveEntry;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 unk2C0;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 unk2D8;
    unsigned char unk2F0;
    unsigned char undefined_2f1[7];
    BGSSaveLoadManager__Thread thread;
    BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3 unk370;
};
static_assert(sizeof(BGSSaveLoadManager) == 1048, "BGSSaveLoadManager layout differs from the PDB");
