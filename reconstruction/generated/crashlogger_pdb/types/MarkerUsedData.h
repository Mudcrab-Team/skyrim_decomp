// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MarkerUsedData; size 0xc
#pragma once

#include "AITimeStamp.h"
#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
struct MarkerUsedData {
    BSPointerHandle_RE__Actor_1a35f4b9 actorinMarker;
    unsigned int markerID;
    AITimeStamp expiration;
};
static_assert(sizeof(MarkerUsedData) == 12, "MarkerUsedData layout differs from the PDB");
