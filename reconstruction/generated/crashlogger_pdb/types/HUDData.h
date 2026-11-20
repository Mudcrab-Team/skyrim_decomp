// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HUDData; size 0x48
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "HUD_MESSAGE_TYPE.h"
#include "IUIMessageData.h"
#include "MARKER_TYPE.h"
struct TESQuest_fe66f8e1;
struct TESWordOfPower_c5d95667;
struct HUDData {
    IUIMessageData _base;
    HUD_MESSAGE_TYPE type;
    unsigned int pad14;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce text;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 crosshairRef;
    unsigned int pad2C;
    TESQuest_fe66f8e1* quest;
    TESWordOfPower_c5d95667* wordOfPower;
    bool show;
    unsigned char pad41;
    unsigned short pad42;
    MARKER_TYPE discovery;
};
static_assert(sizeof(HUDData) == 72, "HUDData layout differs from the PDB");
