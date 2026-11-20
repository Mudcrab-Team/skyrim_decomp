// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LocalMapMenu; size 0x30400
#pragma once

#include "BSTArray_RE__MapMenuMarker_591ae6e2.h"
#include "GFxValue.h"
#include "LocalMapCullingProcess.h"
struct LocalMapMenu {
    BSTArray_RE__MapMenuMarker_591ae6e2 mapMarkers;
    GFxValue unk00018;
    float unk00030;
    float unk00034;
    float unk00038;
    float unk0003C;
    LocalMapCullingProcess localCullingProcess;
    unsigned char runtimeData_raw[96];
};
static_assert(sizeof(LocalMapMenu) == 197632, "LocalMapMenu layout differs from the PDB");
