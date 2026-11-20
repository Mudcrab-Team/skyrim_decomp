// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESContainerChangedEvent; size 0x18
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
struct TESContainerChangedEvent {
    unsigned int oldContainer;
    unsigned int newContainer;
    unsigned int baseObj;
    int itemCount;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 reference;
    unsigned short uniqueID;
    unsigned short pad16;
};
static_assert(sizeof(TESContainerChangedEvent) == 24, "TESContainerChangedEvent layout differs from the PDB");
