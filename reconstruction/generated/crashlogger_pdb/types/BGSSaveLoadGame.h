// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveLoadGame; size 0x348
#pragma once

#include "BGSConstructFormsInAllFilesMap.h"
#include "BGSSaveLoadFormIDMap.h"
#include "BGSSaveLoadHistory.h"
#include "BGSSaveLoadQueuedSubBufferMap.h"
#include "BGSSaveLoadReferencesMap.h"
#include "BSTArray_RE__BGSLoadFormData_3a1d9293.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_28d95133.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9.h"
#include "GlobalFlags.h"
#include "TESFileCollection.h"
struct BGSSaveLoadChangesMap;
struct BGSSaveLoadGame {
    TESFileCollection savedFiles;
    BGSSaveLoadFormIDMap worldspaceFormIDMap;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_28d95133 queuedInitPackageLocations;
    BGSSaveLoadReferencesMap references;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9 changedFormIDs;
    BGSConstructFormsInAllFilesMap reconstructFormsMap;
    BGSSaveLoadQueuedSubBufferMap queuedSubBuffersMap;
    BGSSaveLoadFormIDMap formIDMap;
    BGSSaveLoadHistory history;
    BSTArray_RE__BGSLoadFormData_3a1d9293 loadFormData;
    BGSSaveLoadChangesMap* saveLoadChanges;
    BGSSaveLoadChangesMap* oldChangesMap;
    GlobalFlags globalFlags;
    unsigned char currentMinorVersion;
    unsigned char undefined_345[3];
};
static_assert(sizeof(BGSSaveLoadGame) == 840, "BGSSaveLoadGame layout differs from the PDB");
