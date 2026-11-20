// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMusicManager; size 0x38
#pragma once

#include "BSTArray_RE__BSIMusicType_968d6439.h"
#include "BSTEventSink_RE__BSMusicEvent_52d96573.h"
#include "BSTSingletonSDM_RE__BSMusicManager_055873b5.h"
struct BSIMusicType_8f0bc6cf;
struct BSMusicManager {
    BSTEventSink_RE__BSMusicEvent_52d96573 _base;
    BSTSingletonSDM_RE__BSMusicManager_055873b5 _base_BSTSingletonSDM_RE_BSMusicManager_;
    unsigned char undefined_9[7];
    BSTArray_RE__BSIMusicType_968d6439 musicQueue;
    BSIMusicType_8f0bc6cf* current;
    unsigned int unk30;
    unsigned int pad34;
};
static_assert(sizeof(BSMusicManager) == 56, "BSMusicManager layout differs from the PDB");
