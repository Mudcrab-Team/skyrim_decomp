// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PackageLocation; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Data_3cacc8c9.h"
#include "IAIWorldLocationHandle_9d3175f8.h"
struct PackageLocation {
    IAIWorldLocationHandle_9d3175f8 _base;
    unsigned char locType;  // Type in the PDB is wider than this slot
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int rad;
    Data_3cacc8c9 data;
};
static_assert(sizeof(PackageLocation) == 24, "PackageLocation layout differs from the PDB");
