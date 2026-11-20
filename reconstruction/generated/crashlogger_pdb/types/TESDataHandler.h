// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESDataHandler; size 0xdc0
#pragma once

#include "BSSimpleList_RE__TESFile_c7cbc6df.h"
#include "BSTSingletonSDM_RE__TESDataHandler_f3869707.h"
#include "NiTList_RE__TESForm_bf037599.h"
#include "NiTPrimitiveArray_RE__BGSAddonNode_c5746d60.h"
#include "NiTPrimitiveArray_RE__TESObjectCELL_0b1122da.h"
#include "TESFileCollection.h"
struct InventoryChanges;
struct TESFile_8388152d;
struct TESObjectList;
struct TESRegionDataManager;
struct TESRegionList;
struct TESDataHandler {
    BSTSingletonSDM_RE__TESDataHandler_f3869707 _base;
    unsigned char pad001;
    unsigned short pad002;
    unsigned int pad004;
    TESObjectList* objectList;
    unsigned char formArrays_raw[3312];
    TESRegionList* regionList;
    NiTPrimitiveArray_RE__TESObjectCELL_0b1122da interiorCells;
    NiTPrimitiveArray_RE__BGSAddonNode_c5746d60 addonNodes;
    NiTList_RE__TESForm_bf037599 badForms;
    unsigned int nextID;
    unsigned int padD54;
    TESFile_8388152d* activeFile;
    BSSimpleList_RE__TESFile_c7cbc6df files;
    TESFileCollection compiledFileCollection;
    bool masterSave;
    bool blockSave;
    bool saveLoadGame;
    bool autoSaving;
    bool exportingPlugin;
    bool clearingData;
    bool hasDesiredFiles;
    bool checkingModels;
    bool loadingFiles;
    bool dontRemoveIDs;
    unsigned char gameSettingsLoadState;
    unsigned char padDAB;
    unsigned int padDAC;
    TESRegionDataManager* regionDataManager;
    InventoryChanges* merchantInventory;
};
static_assert(sizeof(TESDataHandler) == 3520, "TESDataHandler layout differs from the PDB");
