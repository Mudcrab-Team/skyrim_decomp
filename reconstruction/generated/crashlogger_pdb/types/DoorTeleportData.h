// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DoorTeleportData; size 0x20
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "NiPoint3.h"
struct DoorTeleportData {
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 linkedDoor;
    NiPoint3 position;
    NiPoint3 rotation;
    unsigned char flags;
    unsigned char pad1D;
    unsigned short pad1E;
};
static_assert(sizeof(DoorTeleportData) == 32, "DoorTeleportData layout differs from the PDB");
