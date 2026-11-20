// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWorldSpace; size 0x358
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSLargeRefData.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "BSTArray_RE__NiPointer_RE__TESObjectREFR_24b49f73.h"
#include "BSTScatterTable_RE__BSCRC32_RE__CellID_std__equal_to_RE__CellID_RE__BSTScatterTableTrai_1e2f2d3b.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_a45f049f.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_f82f4032.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860.h"
#include "NiPoint2.h"
#include "NiPointer_RE__BSPortalGraph_203711a1.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "ShortPoint.h"
#include "TESForm_4074aa87.h"
#include "TESFullName_88f61e2a.h"
#include "TESModel.h"
#include "TESTexture_fe82fffc.h"
#include "WORLD_MAP_DATA.h"
#include "WORLD_MAP_OFFSET_DATA.h"
struct BGSEncounterZone_a1aa56ae;
struct BGSLightingTemplate_493da35d;
struct BGSLocation_075ae773;
struct BGSMusicType;
struct BGSTerrainManager;
struct RE__NiTPointerMap_unsigned_int_RE__BSSimpleList_RE__TESObjectREFR_599bafb4;
struct TESClimate;
struct TESObjectCELL;
struct TESWaterForm;
struct TESWorldSpace_f9563d31 {
    TESForm_4074aa87 _base;
    TESFullName_88f61e2a _base_TESFullName;
    TESModel _base_TESModel;
    BSTScatterTable_RE__BSCRC32_RE__CellID_std__equal_to_RE__CellID_RE__BSTScatterTableTrai_1e2f2d3b cellMap;
    TESObjectCELL* persistentCell;
    BGSTerrainManager* terrainManager;
    TESClimate* climate;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char unk0A1;
    unsigned short parentUseFlags;  // ParentUseFlag in the PDB is wider than this slot
    ShortPoint fixedCenter;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_f82f4032 fixedPersistentRefMap;
    BSTArray_RE__NiPointer_RE__TESObjectREFR_24b49f73 mobilePersistentRefs;
    RE__NiTPointerMap_unsigned_int_RE__BSSimpleList_RE__TESObjectREFR_599bafb4* overlappedMultiboundMap;
    TESObjectCELL* skyCell;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_a45f049f locationMap;
    NiPointer_RE__BSPortalGraph_203711a1 portalGraph;
    void* unk138;
    void* unk140;
    NiPointer_RE__NiNode_28171d5b multiBoundNode;
    NiPointer_RE__NiNode_28171d5b portalSharedNode;
    TESWorldSpace_f9563d31* parentWorld;
    BGSLightingTemplate_493da35d* lightingTemplate;
    TESWaterForm* worldWater;
    TESWaterForm* lodWater;
    float lodWaterHeight;
    unsigned int pad17C;
    unsigned long long unk180;
    WORLD_MAP_DATA worldMapData;
    WORLD_MAP_OFFSET_DATA worldMapOffsetData;
    unsigned int pad1B4;
    BGSMusicType* musicType;
    NiPoint2 minimumCoords;
    NiPoint2 maximumCoords;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 offsetDataMap;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce editorID;
    float defaultLandHeight;
    float defaultWaterHeight;
    float distantLODMult;
    unsigned int pad21C;
    BGSEncounterZone_a1aa56ae* encounterZone;
    BGSLocation_075ae773* location;
    TESTexture_fe82fffc canopyShadowTexture;
    TESTexture_fe82fffc waterEnvMap;
    BGSLargeRefData largeRefData;
    unsigned long long unk2E0;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 unk2E8;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 unk318;
    float northRotation;
    unsigned int pad34C;
    unsigned char* maxHeightData;
};
static_assert(sizeof(TESWorldSpace_f9563d31) == 856, "TESWorldSpace_f9563d31 layout differs from the PDB");
