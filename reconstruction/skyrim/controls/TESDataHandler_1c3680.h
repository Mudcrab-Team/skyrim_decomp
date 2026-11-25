// New function names and signatures, unknown global names, and newly split unknown regions: GUESS(low); declarations follow the observed operations.
// Source exposure: mixed (community-generated layout and the pinned image listing).
// Code origin: layout declarations adapted from the labelled generated CrashLogger header; new method declarations inferred locally.
// TESDataHandler and its member layout: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstdint>


#include <cstdint>

#include "generated/crashlogger_pdb/types/BSSimpleList_RE__TESFile_c7cbc6df.h"
#include "generated/crashlogger_pdb/types/BSTSingletonSDM_RE__TESDataHandler_f3869707.h"
#include "generated/crashlogger_pdb/types/NiTList_RE__TESForm_bf037599.h"
#include "generated/crashlogger_pdb/types/NiTPrimitiveArray_RE__BGSAddonNode_c5746d60.h"
#include "generated/crashlogger_pdb/types/NiTPrimitiveArray_RE__TESObjectCELL_0b1122da.h"
#include "generated/crashlogger_pdb/types/TESFileCollection.h"
struct InventoryChanges;
struct TESFile_8388152d;
struct TESObjectList;
struct TESRegionDataManager;
struct TESRegionList;
struct TESDataHandler {
public:
    std::uint16_t Function1bade0() const;

public:
    bool IsTemporaryFormID(std::uint32_t a_formID);

    BSTSingletonSDM_RE__TESDataHandler_f3869707 _base;
    unsigned char unknown001;
    unsigned short unknown002;
    unsigned int unknown004;
    TESObjectList* objectList;
    unsigned char formArrays_raw[3312];
    TESRegionList* regionList;
    NiTPrimitiveArray_RE__TESObjectCELL_0b1122da interiorCells;
    NiTPrimitiveArray_RE__BGSAddonNode_c5746d60 addonNodes;
    NiTList_RE__TESForm_bf037599 badForms;
    unsigned int nextID;
    unsigned int unknownD54;
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
    unsigned char unknownDAB;
    unsigned int unknownDAC;
    TESRegionDataManager* regionDataManager;
    InventoryChanges* merchantInventory;
};
static_assert(sizeof(TESDataHandler) == 3520, "TESDataHandler layout differs from the PDB");
