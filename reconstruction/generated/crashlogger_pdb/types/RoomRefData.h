// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RoomRefData; size 0x38
#pragma once

#include "BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12_8c679da3.h"
struct BGSLightingTemplate;
struct TESImageSpace_93cfb701;
struct RoomRefData {
    BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12_8c679da3 portalList;
    BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12_8c679da3 roomList;
    unsigned char master;
    unsigned char pad21;
    unsigned short pad22;
    unsigned int pad24;
    BGSLightingTemplate* lightingTemplate;
    TESImageSpace_93cfb701* imageSpace;
};
static_assert(sizeof(RoomRefData) == 56, "RoomRefData layout differs from the PDB");
