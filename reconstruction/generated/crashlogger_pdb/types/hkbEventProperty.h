// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbEventProperty; size 0x10
#pragma once

#include "hkbEventBase.h"
struct hkbEventProperty {
    hkbEventBase _base;
};
static_assert(sizeof(hkbEventProperty) == 16, "hkbEventProperty layout differs from the PDB");
