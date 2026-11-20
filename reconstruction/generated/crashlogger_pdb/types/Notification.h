// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Notification; size 0x60
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "BSTArray_RE__detail__BSFixedString_char_dee190e5_40d0985f.h"
#include "EnumSet_RE__HUD_MESSAGE_TYPE_unsigned_int_f55f4a73.h"
struct TESQuest;
struct TESWordOfPower;
struct Notification {
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce text;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce status;
    BSFixedString_char_83b572b4 sound;
    BSTArray_RE__detail__BSFixedString_char_dee190e5_40d0985f objectives;
    EnumSet_RE__HUD_MESSAGE_TYPE_unsigned_int_f55f4a73 type;
    unsigned int pad44;
    TESQuest* quest;
    TESWordOfPower* word;
    unsigned int time;
    unsigned int pad5C;
};
static_assert(sizeof(Notification) == 96, "Notification layout differs from the PDB");
