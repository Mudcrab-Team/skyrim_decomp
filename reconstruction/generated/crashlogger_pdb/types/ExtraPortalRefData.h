// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPortalRefData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct PortalLinkedRefData;
struct ExtraPortalRefData {
    BSExtraData_4ca6af76 _base;
    PortalLinkedRefData* data;
};
static_assert(sizeof(ExtraPortalRefData) == 24, "ExtraPortalRefData layout differs from the PDB");
