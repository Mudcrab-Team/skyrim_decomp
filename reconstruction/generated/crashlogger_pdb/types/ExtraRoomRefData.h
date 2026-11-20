// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraRoomRefData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct RoomRefData;
struct ExtraRoomRefData {
    BSExtraData_4ca6af76 _base;
    RoomRefData* data;
};
static_assert(sizeof(ExtraRoomRefData) == 24, "ExtraRoomRefData layout differs from the PDB");
