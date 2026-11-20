// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWorldSpace; size 0x358
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSLargeRefData.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "BSTArray_RE__NiPointer_RE__TESObjectREFR_24b49f73_bc2ec299.h"
#include "BSTScatterTable_RE__BSCRC32_RE__CellID_std__equal_to_RE__CellID_RE__BSTScatterTableTrai_1e2f2d3b.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_a45f049f.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_f82f4032.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860.h"
#include "NiPoint2_6bdffc9f.h"
#include "NiPointer_RE__BSPortalGraph_203711a1.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "ShortPoint.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESModel_c52655e4.h"
#include "TESTexture.h"
#include "WORLD_MAP_DATA.h"
#include "WORLD_MAP_OFFSET_DATA.h"
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLocation;
struct BGSMusicType_01bbbee6;
struct BGSTerrainManager_f525841a;
struct RE__NiTPointerMap_unsigned_int_RE__BSSimpleList_RE__TESObjectREFR_599bafb4;
struct TESClimate_c9cfcf5f;
struct TESObjectCELL_f81013b3;
struct TESWaterForm_2ffdeaeb;
struct TESWorldSpace {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESModel_c52655e4 _base_TESModel;
    BSTScatterTable_RE__BSCRC32_RE__CellID_std__equal_to_RE__CellID_RE__BSTScatterTableTrai_1e2f2d3b cellMap;
    TESObjectCELL_f81013b3* persistentCell;
    BGSTerrainManager_f525841a* terrainManager;
    TESClimate_c9cfcf5f* climate;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char unk0A1;
    unsigned short parentUseFlags;  // ParentUseFlag in the PDB is wider than this slot
    ShortPoint fixedCenter;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_f82f4032 fixedPersistentRefMap;
    BSTArray_RE__NiPointer_RE__TESObjectREFR_24b49f73_bc2ec299 mobilePersistentRefs;
    RE__NiTPointerMap_unsigned_int_RE__BSSimpleList_RE__TESObjectREFR_599bafb4* overlappedMultiboundMap;
    TESObjectCELL_f81013b3* skyCell;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_a45f049f locationMap;
    NiPointer_RE__BSPortalGraph_203711a1 portalGraph;
    void* unk138;
    void* unk140;
    NiPointer_RE__NiNode_28171d5b multiBoundNode;
    NiPointer_RE__NiNode_28171d5b portalSharedNode;
    TESWorldSpace* parentWorld;
    BGSLightingTemplate* lightingTemplate;
    TESWaterForm_2ffdeaeb* worldWater;
    TESWaterForm_2ffdeaeb* lodWater;
    float lodWaterHeight;
    unsigned int pad17C;
    unsigned long long unk180;
    WORLD_MAP_DATA worldMapData;
    WORLD_MAP_OFFSET_DATA worldMapOffsetData;
    unsigned int pad1B4;
    BGSMusicType_01bbbee6* musicType;
    NiPoint2_6bdffc9f minimumCoords;
    NiPoint2_6bdffc9f maximumCoords;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 unk1D0;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce editorID;
    float defaultLandHeight;
    float defaultWaterHeight;
    float distantLODMult;
    unsigned int pad21C;
    BGSEncounterZone* encounterZone;
    BGSLocation* location;
    TESTexture canopyShadowTexture;
    TESTexture waterEnvMap;
    BGSLargeRefData largeRefData;
    unsigned long long unk2E0;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 unk2E8;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 unk318;
    float northRotation;
    unsigned int pad34C;
    unsigned char* maxHeightData;
};
static_assert(sizeof(TESWorldSpace) == 856, "TESWorldSpace layout differs from the PDB");
