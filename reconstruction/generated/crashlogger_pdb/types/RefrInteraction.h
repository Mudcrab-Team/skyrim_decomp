// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RefrInteraction; size 0x20
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "SyncQueueObj.h"
struct RefrInteraction {
    SyncQueueObj _base;
    BSPointerHandle_RE__Actor_1a35f4b9 actor;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 targetRefr;
    bool synced;
    unsigned char pad19;
    unsigned short pad1A;
    unsigned int pad1C;
};
static_assert(sizeof(RefrInteraction) == 32, "RefrInteraction layout differs from the PDB");
