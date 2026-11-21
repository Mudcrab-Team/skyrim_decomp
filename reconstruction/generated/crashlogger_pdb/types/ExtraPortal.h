// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPortal; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "NiPointer_RE__BSPortal_25afb0c4.h"
struct ExtraPortal {
    BSExtraData_4ca6af76 _base;
    NiPointer_RE__BSPortal_25afb0c4 portal;
};
static_assert(sizeof(ExtraPortal) == 24, "ExtraPortal layout differs from the PDB");
