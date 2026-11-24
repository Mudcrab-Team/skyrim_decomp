// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Source exposure: mixed (community-generated layout and the pinned image listing).
// Code origin: layout declarations adapted from the labelled generated CrashLogger header; new method declarations inferred locally.
// BGSSaveLoadManager and its member layout: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstdint>

namespace ReconstructedBGSSaveLoadManager {

#include <cstdint>

#include "generated/crashlogger_pdb/types/BGSSaveLoadManager__Thread.h"
#include "generated/crashlogger_pdb/types/BSFixedString_char_83b572b4.h"
#include "generated/crashlogger_pdb/types/BSTArray_RE__BGSSaveLoadFileEntry_de5d1f14.h"
#include "generated/crashlogger_pdb/types/BSTArray_RE__BGSSaveLoadManager__SaveEntry_424aa5fb.h"
#include "generated/crashlogger_pdb/types/BSTArray_RE__detail__BSFixedString_char_dee190e5.h"
#include "generated/crashlogger_pdb/types/BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3.h"
#include "generated/crashlogger_pdb/types/BSTEventSink_RE__BSSaveDataEvent_771b90b5.h"
#include "generated/crashlogger_pdb/types/BSTEventSink_RE__BSSystemEvent_a1441324.h"
#include "generated/crashlogger_pdb/types/BSTEventSink_RE__RaceSexMenuEvent__NameChangedEvent_5a180ea4.h"
#include "generated/crashlogger_pdb/types/BSTEventSource_RE__BGSSaveLoadManagerEvent_d762136b.h"
#include "generated/crashlogger_pdb/types/BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_f36d4f05.h"
struct BGSSaveLoadFileEntry;
struct BGSSaveLoadManager {
public:
    void Function623910();

public:
    void Function623930(BSTArray_RE__BGSSaveLoadFileEntry_de5d1f14* a_list);

public:
    std::uint8_t Function6247a0() const;

public:
    static std::uint32_t Function623450();

public:
    void Function6233b0(std::uint8_t a_value);

public:
    bool Function624780() const;

public:
    bool Function624d50() const;

public:
    static void Function623d90(std::uint8_t a_value);

public:
    static std::uint8_t Function623460();

public:
    BSTArray_RE__BGSSaveLoadFileEntry_de5d1f14* Function6239f0();

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
    unsigned char unknown119;
    unsigned short unknown11A;
    unsigned int saveCount;
    unsigned char unk120;
    unsigned char unknown121;
    unsigned short unknown122;
    unsigned int unknown124;
    unsigned long long tickCount;
    unsigned char unk130;
    unsigned char unknown131;
    unsigned short unknown132;
    unsigned int unknown134;
    unsigned char lastFileFullName[260];
    unsigned int unknown23C;
    BSFixedString_char_83b572b4 lastFileName;
    unsigned short lastFileNameLength;
    unsigned short maxFileNameLength;
    unsigned int unk24C;
    int unk250;
    unsigned int unknown254;
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
    unsigned char unknown2b4[4];
    BGSSaveLoadFileEntry* pendingSaveEntry;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 unk2C0;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 unk2D8;
    unsigned char unk2F0;
    unsigned char unknown2f1[7];
    BGSSaveLoadManager__Thread thread;
    BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3 unk370;
};
static_assert(sizeof(BGSSaveLoadManager) == 1048, "BGSSaveLoadManager layout differs from the PDB");

extern std::uint8_t unknownSaveState1908e3c;
extern std::uint8_t unknownSaveState20b5440;
extern std::uint32_t unknownSaveState1908e34;

}
